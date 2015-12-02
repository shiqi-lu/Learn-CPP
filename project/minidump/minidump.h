#include <windows.h>
#include <DbgHelp.h>
#include <stdlib.h>

#include <boost/filesystem.hpp>

#include "dokan/dayudokan.hpp"
#include "util/dayufsconfig.hpp"

#ifndef _M_IX86
#error "The following code only works for x86!"
#endif

extern std::string srvName;

inline BOOL IsDataSectionNeeded(const WCHAR* pModuleName)
{
    if(pModuleName == 0)
    {
        return FALSE;
    }

    WCHAR szFileName[_MAX_FNAME] = L"";
    _wsplitpath(pModuleName, NULL, NULL, szFileName, NULL);

    if(wcsicmp(szFileName, L"ntdll") == 0)
        return TRUE;

    return FALSE;
}

inline BOOL CALLBACK MiniDumpCallback(PVOID                            pParam,
                                      const PMINIDUMP_CALLBACK_INPUT   pInput,
                                      PMINIDUMP_CALLBACK_OUTPUT        pOutput)
{
    if(pInput == 0 || pOutput == 0)
        return FALSE;

    switch(pInput->CallbackType)
    {
    case ModuleCallback:
        if(pOutput->ModuleWriteFlags & ModuleWriteDataSeg)
            if(!IsDataSectionNeeded(pInput->Module.FullPath))
                pOutput->ModuleWriteFlags &= (~ModuleWriteDataSeg);
    case IncludeModuleCallback:
    case IncludeThreadCallback:
    case ThreadCallback:
    case ThreadExCallback:
        return TRUE;
    default:;
    }

    return FALSE;
}

inline void CreateMiniDump(PEXCEPTION_POINTERS pep, LPCTSTR strFileName)
{
    HANDLE hFile = CreateFile(strFileName, GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if((hFile != NULL) && (hFile != INVALID_HANDLE_VALUE))
    {
        MINIDUMP_EXCEPTION_INFORMATION mdei;
        mdei.ThreadId           = GetCurrentThreadId();
        mdei.ExceptionPointers  = pep;
        mdei.ClientPointers     = FALSE;

        MINIDUMP_CALLBACK_INFORMATION mci;
        mci.CallbackRoutine     = (MINIDUMP_CALLBACK_ROUTINE)MiniDumpCallback;
        mci.CallbackParam       = 0;

        ::MiniDumpWriteDump(::GetCurrentProcess(), ::GetCurrentProcessId(), hFile, MiniDumpNormal, (pep != 0) ? &mdei : 0, NULL, &mci);

        CloseHandle(hFile);
    }
}

LONG __stdcall MyUnhandledExceptionFilter(PEXCEPTION_POINTERS pExceptionInfo)
{
    namespace fs = boost::filesystem;
    WCHAR fn[MAX_PATH] = {0};
    WCHAR lpMainDir[MAX_PATH] = {0};
    GetModuleFileName(NULL, fn, MAX_PATH);
    wcscpy(lpMainDir, fn);

    // Set working dir
    int i = 0;
    for(i = wcslen(lpMainDir) - 1; i > 0 && lpMainDir[i] != L'\\'; --i) {
        // do nothing
    }
    lpMainDir[i] = L'\0';

    SYSTEMTIME sysTime = {0};
    WCHAR path[MAX_PATH] = {0};
    GetSystemTime(&sysTime);
    if (sysTime.wHour > 15) {
        swprintf_s(path, ARRAYSIZE(path),
            L"%s\\dayuwinsrv_%04u-%02u-%02u_%02u-%02u-%02u.dmp",
            lpMainDir, sysTime.wYear, sysTime.wMonth, sysTime.wDay + 1,
            sysTime.wHour - 16, sysTime.wMinute, sysTime.wSecond);
    } else {
        swprintf_s(path, ARRAYSIZE(path),
            L"%s\\dayuwinsrv_%04u-%02u-%02u_%02u-%02u-%02u.dmp",
            lpMainDir, sysTime.wYear, sysTime.wMonth, sysTime.wDay,
            sysTime.wHour + 8, sysTime.wMinute, sysTime.wSecond);
    }

    CreateMiniDump(pExceptionInfo, path);

    /*
    fs::path config_dir = fs::path(lpMainDir) / "config";
    fs::path log_dir = fs::path(lpMainDir) / "log";
    DayufsConfig cfg;
    cfg.set_env(config_dir.wstring(), log_dir.wstring());

    if (!DayufsConfig::init_xml()) {
        // continue;
    }

    cfg.get_config(srvName);

    std::string cmsip = cfg.cmsip();

    std::ofstream out("c:\\a.txt", std::ios::trunc);
    if (out.is_open()) {
        fs::path tmp = path;
        out << "name: " << srvName << std::endl;
        out << "path: " << tmp.string() << std::endl;
        out << "log_path: " << log_dir.string() << std::endl;
        out << "config_path: " << config_dir.string() << std::endl;
        out << "cmsip: " << cmsip << std::endl;
        out.close();
    }

    dayudokan_umount();
    dayudokan_mount(cfg.mount_point());
*/
    return EXCEPTION_EXECUTE_HANDLER;
}

// 此函数一旦成功调用，之后对 SetUnhandledExceptionFilter 的调用将无效
void DisableSetUnhandledExceptionFilter()
{
    void* addr = (void*)GetProcAddress(LoadLibrary(L"kernel32.dll"),
        "SetUnhandledExceptionFilter");

    if (addr)
    {
        unsigned char code[16];
        int size = 0;

        code[size++] = 0x33;
        code[size++] = 0xC0;
        code[size++] = 0xC2;
        code[size++] = 0x04;
        code[size++] = 0x00;

        DWORD dwOldFlag, dwTempFlag;
        VirtualProtect(addr, size, PAGE_READWRITE, &dwOldFlag);
        WriteProcessMemory(GetCurrentProcess(), addr, code, size, NULL);
        VirtualProtect(addr, size, dwOldFlag, &dwTempFlag);
    }
}

void InitMinDump()
{
    //注册异常处理函数
    SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);
    //AddVectoredExceptionHandler(1, MyUnhandledExceptionFilter);

    //使SetUnhandledExceptionFilter
    DisableSetUnhandledExceptionFilter();
}
