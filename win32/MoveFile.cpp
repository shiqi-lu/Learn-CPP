/*
g++ MoveFile.cpp -I$CPPET/include -static-libgcc -static-libstdc++ $CPPET/lib/libboost_unit_test_framework.a $CPPET/lib/libboost_system.a $CPPET/lib/libboost_filesystem.a
*/
#define BOOST_TEST_MODULE MoveFileTest

#include <iostream>
#include <windows.h>
#include "util.hpp"

#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(move_file_test)

namespace fs = boost::filesystem;

BOOST_AUTO_TEST_CASE(move_file)
{
    if (fs::exists("test_move_filekkk8")) {
        fs::remove_all("test_move_filekkk8");
    }

    // create test environment
    DWORD done;
    done = CreateDirectory("test_move_filekkk8", NULL);
    BOOST_REQUIRE_MESSAGE(done >= 0, format_errmsg(GetLastError()));

    done = CreateDirectory("test_move_filekkk8\\folder2", NULL);
    BOOST_REQUIRE_MESSAGE(done >= 0, format_errmsg(GetLastError()));

    HANDLE ret1 = CreateFile("test_move_filekkk8\\abc123", 
                     GENERIC_READ | GENERIC_WRITE, 0, NULL,
                     CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
    BOOST_REQUIRE_MESSAGE(ret1 != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));
    CloseHandle(ret1);
    HANDLE ret2 = CreateFile("test_move_filekkk8\\cde456", 
                     GENERIC_READ | GENERIC_WRITE, 0, NULL,
                     CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
    BOOST_REQUIRE_MESSAGE(ret2 != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));
    //CloseHandle(ret2);

    HANDLE ret3 = CreateFile("test_move_filekkk8\\folder2\\kkx", 
                     GENERIC_READ | GENERIC_WRITE, 0, NULL,
                     CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
    BOOST_REQUIRE_MESSAGE(ret3 != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));
    CloseHandle(ret3);

    // Rename an close file
    done = MoveFile("test_move_filekkk8\\abc123", "test_move_filekkk8\\xyz789");
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // rename an open file
    done = MoveFile("test_move_filekkk8\\cde456", "test_move_filekkk8\\ijk345");
    //BOOST_WARN_MESSAGE(false, GetLastError());
    //BOOST_WARN_MESSAGE(done == 0, GetLastError());
    Sleep(2);
    BOOST_REQUIRE_MESSAGE(done == 0, format_errmsg(GetLastError()));
    
    CloseHandle(ret2);


    

    // clear environment
    //system("rmdir /s /q test_move_filekkk8");

    /*SHFILEOPSTRUCT FileOp;
    FileOp.fFlags = FOF_NOCONFIRMATION | FOF_NOERRORUI;
    FileOp.hNameMappings = NULL;
    FileOp.hwnd = NULL;
    FileOp.lpszProgressTitle = NULL;
    FileOp.pFrom = ".\\test_move_filekkk8";
    FileOp.pTo = NULL;
    FileOp.wFunc = FO_DELETE;
    SHFileOperation(&FileOp);*/
    if (fs::exists("test_move_filekkk8")) {
        fs::remove_all("test_move_filekkk8");
    }
}

BOOST_AUTO_TEST_SUITE_END()

