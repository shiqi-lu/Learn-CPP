#include <windows.h>
#include <string>

std::string format_errmsg(DWORD error)
{
    if(error) {
        LPVOID lpMsgBuf;
        DWORD dwFlags = FORMAT_MESSAGE_ALLOCATE_BUFFER |
                        FORMAT_MESSAGE_FROM_SYSTEM |
                        FORMAT_MESSAGE_IGNORE_INSERTS;
        DWORD bufLen = FormatMessageA(dwFlags,
                                      NULL,
                                      error,
                                      MAKELANGID(LANG_ENGLISH,
                                                 SUBLANG_ENGLISH_US),
                                      (LPSTR)&lpMsgBuf,
                                      0,
                                      NULL);
        if(bufLen) {
            LPSTR lpMsgStr = (LPSTR)lpMsgBuf;
            std::string result(lpMsgStr);
            LocalFree(lpMsgBuf);
            return result;
        }
    }
    return std::string();
}
