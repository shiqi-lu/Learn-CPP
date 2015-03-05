// g++ -DUNICODE  -finput-charset=GBK opendir.cpp && ./a.exe
#include <windows.h>
#include <ShlObj.h>
#include <iostream>

using namespace std;

BOOL SelectDir(HWND hWnd)
{
    BROWSEINFO bifolder;
    wchar_t FileName[MAX_PATH];
    ZeroMemory(&bifolder, sizeof(BROWSEINFO)); 
    bifolder.hwndOwner = hWnd;              // 拥有者句柄
    bifolder.pszDisplayName = FileName;     // 存放目录路径缓冲区
    bifolder.lpszTitle = TEXT("请选择文件夹");  // 标题
    bifolder.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX; // 新的样式,带编辑框

    LPITEMIDLIST idl = SHBrowseForFolder(&bifolder);
    if (idl == NULL)
    {
        return FALSE;
    }

    SHGetPathFromIDList(idl,FileName);    
    MessageBox(hWnd, FileName, TEXT("错误信息"), MB_OK|MB_ICONERROR);
    return TRUE;
}

int main()
{
    SelectDir(NULL);

    return 0;
}
