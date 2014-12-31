/*
g++ IfsCaseSensitive.cpp -I$CPPET/include -static-libgcc -static-libstdc++ $CPPET/lib/libboost_unit_test_framework.a $CPPET/lib/libboost_system.a $CPPET/lib/libboost_filesystem.a -o IfsCaseSensitive.exe && strip -s IfsCaseSensitive.exe
*/
#define BOOST_TEST_MODULE IfsCaseSensitive

#include <windows.h>
#include "util.hpp"

#include <string>

#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ifs_case_sensitive)

namespace fs = boost::filesystem;

BOOST_AUTO_TEST_CASE(case_sensitive)
{
    // Clean the test environment
    if (fs::exists("case_senii23")) {
        fs::remove_all("case_senii23");
    }

    // Create test directory
    DWORD done;
    done = CreateDirectory("case_senii23", NULL);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // Create file
    HANDLE ret = CreateFile("case_senii23\\macos.txt", 
                    GENERIC_READ | GENERIC_WRITE, 0, NULL,
                    CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
    BOOST_REQUIRE_MESSAGE(ret != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));

    // Write file
    const int BUFSIZE = 4096;
    char chBuffer[BUFSIZE];
    memcpy(chBuffer, "macos23", 7);
    DWORD dwWritenSize = 0;
    done = WriteFile(ret, chBuffer, 7, &dwWritenSize, NULL);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // force to flush file
    FlushFileBuffers(ret);

    // Close file
    done = CloseHandle(ret);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));


    // Create file
    HANDLE ret1 = CreateFile("case_senii23\\MacOs.txt", 
                    GENERIC_READ | GENERIC_WRITE, 0, NULL,
                    CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
    BOOST_REQUIRE_MESSAGE(ret1 != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));

    // Write file
    char chBuffer1[BUFSIZE];
    memcpy(chBuffer1, "oooooooi", 8);
    dwWritenSize = 0;
    done = WriteFile(ret1, chBuffer1, 8, &dwWritenSize, NULL);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // force to flush file
    FlushFileBuffers(ret1);

    // Close file
    done = CloseHandle(ret1);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    WIN32_FIND_DATA wfd;
    HANDLE fnd = FindFirstFile("case_senii23\\macos.txt",
                               &wfd);
    BOOST_REQUIRE_MESSAGE(fnd != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));
    done = FindClose(fnd);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    WIN32_FIND_DATA wfd1;
    HANDLE fnd1 = FindFirstFile("case_senii23\\MacOs.txt",
                               &wfd1);
    BOOST_REQUIRE_MESSAGE(fnd1 != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));
    done = FindClose(fnd1);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));


    ret = CreateFile("case_senii23\\macos.txt", 
                    GENERIC_READ | GENERIC_WRITE, 0, NULL,
                    OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    BOOST_REQUIRE_MESSAGE(ret != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));

    ret1 = CreateFile("case_senii23\\MacOs.txt", 
                    GENERIC_READ | GENERIC_WRITE, 0, NULL,
                    OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    BOOST_REQUIRE_MESSAGE(ret1 != INVALID_HANDLE_VALUE,
                          format_errmsg(GetLastError()));


    // Read file
    DWORD dwReadSize = 0;
    done = ReadFile(ret, chBuffer, 7, &dwReadSize, NULL);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));
    std::string lower = chBuffer;
    BOOST_REQUIRE_MESSAGE(lower == "macos23", format_errmsg(GetLastError()));


    // Read file
    dwReadSize = 0;
    done = ReadFile(ret1, chBuffer1, 8, &dwReadSize, NULL);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));
    std::string upper = chBuffer1;
    BOOST_REQUIRE_MESSAGE(upper == "oooooooi", format_errmsg(GetLastError()));


    done = CloseHandle(ret);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));
    done = CloseHandle(ret1);
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // Delete file
    done = DeleteFile("case_senii23\\macos.txt");
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    done = DeleteFile("case_senii23\\MacOs.txt");
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));

    // Delete directory
    done = RemoveDirectory("case_senii23");
    BOOST_REQUIRE_MESSAGE(done != 0, format_errmsg(GetLastError()));


    /*
    if (fs::exists("test_Basic_Trauiii23")) {
        fs::remove_all("test_Basic_Trauiii23");
    }*/
}
 
BOOST_AUTO_TEST_SUITE_END()
