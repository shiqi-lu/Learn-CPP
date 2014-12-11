#include <stdio.h>
#include <windows.h>

void printLogicalDrives()
{
    TCHAR tc1[50], tc2[50];

    DWORD dw = GetLogicalDrives();
    wsprintf(tc1, "%ld", dw);
    MessageBox(NULL, tc1, "oct", MB_OK);

    _itoa(dw, tc2, 2);
    MessageBox(NULL, tc2, "bin", MB_OK);
}

void logicalDriveNumType()
{
    TCHAR tc[50];
    char c = 'A';
    char drive[4];
    char output[64];
    int count = 0;
    DWORD dw = GetLogicalDrives();
    while (dw != 0) {
        if ((dw & 1 ) != 0) {
            sprintf(drive, "%c:", c);
            switch (GetDriveType(drive))
            {
                case DRIVE_FIXED:
                    sprintf(output, "%c: -- Drive Fixed\n", c);
                    break;
                case DRIVE_REMOVABLE:
                    sprintf(output, "%c: -- Drive Removable\n", c);
                    break;
                case DRIVE_REMOTE:
                    sprintf(output, "%c: -- Drive Remote\n", c);
                    break;
                case DRIVE_CDROM:
                    sprintf(output, "%c: -- CD-Rom\n", c);
                    break;
                case DRIVE_RAMDISK:
                    sprintf(output, "%c: -- Ram Disk\n", c);
                    break;
                case DRIVE_UNKNOWN:
                    sprintf(output, "%c: -- Unknown drive\n", c);
                    break;
                case DRIVE_NO_ROOT_DIR:
                    sprintf(output, "%c: -- root path invalid\n", c);
                    break;
                default:
                    sprintf(output, "%c: -- can't decide\n", c);
                    break;
            }
            printf("%s", output);
            ++count;
            ++c;
        }
        dw >>= 1;
    }
    printf("the drive numbers: %d", count);
    //wsprintf(tc, "the drive numbers: %d", count);
    //MessageBox(NULL, tc, "drive numbers", MB_OK);
}

void testDriveExists()
{
    TCHAR tc[50];
    char ch = 'E';
    int n = ch - 'A';
    DWORD dw = GetLogicalDrives();

    if ((dw != 0) && (dw >>= n) != 0) {
        wsprintf(tc, "%c: exists", ch);
    } else {
        wsprintf(tc, "%c: not exists", ch);
    }
    MessageBox(NULL, tc, "exists?", MB_OK);
}

int main()
{
    //printLogicalDrives();

    logicalDriveNumType();

    //testDriveExists();

    return 0;
}
