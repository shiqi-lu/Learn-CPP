#include <windows.h>
#include <iostream>

#define check(val, flag) if (val & flag) {std::cout << #flag << std::endl;}
/*void check(DWORD val, DWORD flag)
{
    if (val & flag) {
        std::cout << std::hex << flag << std::endl;
    }
}*/

int main()
{
    DWORD fsFlags;
    GetVolumeInformation("Z:\\", NULL, 0, NULL, NULL, &fsFlags, NULL, 0);
    std::cout << fsFlags << std::endl;

    check(fsFlags, FILE_CASE_PRESERVED_NAMES);
    check(fsFlags, FILE_CASE_SENSITIVE_SEARCH);
    check(fsFlags, FILE_FILE_COMPRESSION);
    check(fsFlags, FILE_NAMED_STREAMS);
    check(fsFlags, FILE_PERSISTENT_ACLS);
    check(fsFlags, FILE_READ_ONLY_VOLUME);
    check(fsFlags, FILE_SEQUENTIAL_WRITE_ONCE);
    check(fsFlags, FILE_SUPPORTS_ENCRYPTION);
    check(fsFlags, FILE_SUPPORTS_EXTENDED_ATTRIBUTES);
    check(fsFlags, FILE_SUPPORTS_HARD_LINKS);
    check(fsFlags, FILE_SUPPORTS_OBJECT_IDS);
    check(fsFlags, FILE_SUPPORTS_OPEN_BY_FILE_ID);
    check(fsFlags, FILE_SUPPORTS_REPARSE_POINTS);
    check(fsFlags, FILE_SUPPORTS_SPARSE_FILES);
    check(fsFlags, FILE_SUPPORTS_TRANSACTIONS);
    check(fsFlags, FILE_SUPPORTS_USN_JOURNAL);
    check(fsFlags, FILE_UNICODE_ON_DISK);
    check(fsFlags, FILE_VOLUME_IS_COMPRESSED);
    check(fsFlags, FILE_VOLUME_QUOTAS);

    return 0;
}
