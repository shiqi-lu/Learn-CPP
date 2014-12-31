/*
g++ CaseInSensitive.cpp -I$CPPET/include -static-libgcc -static-libstdc++ $CPPET/lib/libboost_unit_test_framework.a $CPPET/lib/libboost_system.a $CPPET/lib/libboost_filesystem.a -o CaseInSensitive.exe && strip -s CaseInSensitive.exe && ./CaseInSensitive.exe
*/
#define BOOST_TEST_MODULE CaseInSensitiveTest

#include <windows.h>
#include "util.hpp"

#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(case_in_sensitive_test)

namespace fs = boost::filesystem;

BOOST_AUTO_TEST_CASE(case_in_sensitive)
{
    // Clean the test environment
    if (fs::exists("test_Basic_Trauiii23")) {
        fs::remove_all("test_Basic_Trauiii23");
    }
    if (fs::exists("test_Basic_kkkUFO75")) {
        fs::remove_all("test_Basic_kkkUFO75");
    }

    // Create test directory
    DWORD done;
    done = CreateDirectory("test_Basic_Trauiii23", NULL);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // Create file
    HANDLE ret = CreateFile("test_Basic_Trauiii23\\MacOSkz23.txt", 
                    GENERIC_READ | GENERIC_WRITE, 0, NULL,
                    CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
    BOOST_REQUIRE_MESSAGE(ret != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));


    WIN32_FIND_DATA wfd;
    HANDLE fnd = FindFirstFile("test_Basic_Trauiii23\\MACoskz23.txt",
                               &wfd);
    BOOST_REQUIRE_MESSAGE(fnd != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));
    done = FindClose(fnd);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // Write file
    const int BUFSIZE = 4096;
    char chBuffer[BUFSIZE];
    memcpy(chBuffer, "Test213", 7);
    DWORD dwWritenSize = 0;
    done = WriteFile(ret, chBuffer, 7, &dwWritenSize, NULL);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // force to flush file
    FlushFileBuffers(ret);

    // Read file
    DWORD dwReadSize = 0;
    done = ReadFile(ret, chBuffer, 7, &dwReadSize, NULL);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // Close file
    done = CloseHandle(ret);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // Move file
    done = MoveFile("test_Basic_Trauiii23\\MacosKZ23.txt",
                    "test_Basic_Trauiii23\\LinuxCd98.txt");
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // Move directory
    done = MoveFile("test_basic_TrauIII23",
                    "test_Basic_kkkUFO75");
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // Delete file
    done = DeleteFile("test_Basic_kkkUFO75\\LinUXCd98.txt");
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // Delete directory
    done = RemoveDirectory("test_Basic_kkkufo75");
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));


    /*
    if (fs::exists("test_Basic_Trauiii23")) {
        fs::remove_all("test_Basic_Trauiii23");
    }*/
}
 
BOOST_AUTO_TEST_SUITE_END()
