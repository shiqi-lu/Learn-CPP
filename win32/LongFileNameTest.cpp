/***************************************************************************
 * File:      LongFileNameTest.cpp
 *
 * Purpose: . Test whether DayuFS can support Long FileName
 *
 * Caution:   This program can only compile and run in windows
 *
 * Compile Command: g++ -D_UNICODE -DUNICODE -static-libgcc -static-libstdc++
 * LongFileName.cpp -o LongFileName; strip -s LongFileName 
 *
 ***************************************************************************/
#include <windows.h>
#include <iostream>
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

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE HPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    using namespace std;
    wstring mp;
    int length;
    cout << "Please enter the mountpoint(example: R): ";
    wcin >> mp;
    cout << "Please enter the length of filename you want " 
         << "to create(less than 3000 and greater than 0): ";
    cin >> length;
    cout << endl;
    WCHAR filename[3020] = L"\\\\?\\";
    WCHAR dirname[3020] = L"\\\\?\\";
    wcsncat(filename, mp.c_str(), 1);
    wcsncat(dirname, mp.c_str(), 1);
    wcscat(filename, L":\\");
    wcscat(dirname, L":\\");
    WCHAR longname[3000] = L"";
    wcsncat(longname, mp.c_str(), 1);
    wcscat(longname, L":\\");
    for (int i = 0; i < length; ++i) {
        wcscat(filename, L"F");
        wcscat(dirname, L"D");
        wcscat(longname, L"L");
    }
    HANDLE hndl = CreateFile(filename, GENERIC_READ | GENERIC_WRITE, 0,
                             NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hndl == INVALID_HANDLE_VALUE) {
        DWORD aa = GetLastError();
        wcout << filename << std::endl;
        cout << "extended-length filename(" << length << " character):" << endl
             << "Error code: " << aa << endl
             << "Error message: " << format_errmsg(aa) << endl;
    } else {
        cout << "extended-length file created successfully!" << endl;
    }
    HANDLE hndl1 = CreateFile(longname, GENERIC_READ | GENERIC_WRITE, 0,
                             NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hndl == INVALID_HANDLE_VALUE) {
        DWORD aa = GetLastError();
        cout << "filename(" << length << " character):" << endl
             << "Error code: " << aa << endl
             << "Error message: " << format_errmsg(aa) << endl;
    } else {
        cout << "file created successfully!" << endl;
    }
    if (!CreateDirectory(dirname, NULL)) {
        DWORD aa = GetLastError();
        cout << "extended-length directory(" << length << " character):" << endl
             << "Error code: " << aa << endl
             << "Error message: " << format_errmsg(aa) << endl;
    } else {
        cout << "extended-length direcotry created successfully!" << endl;
    }
    CloseHandle(hndl);
    CloseHandle(hndl1);
    return 0;
}
