/* GetUserIndex(int) - 0x800D38F0 (48B) */

extern int g_UserArray[2];

int GetUserIndex(int value);
int GetUserIndex(int value) {
    int* p = g_UserArray;
    int i = 0;
    do {
        int v = *p;
        p++;
        if (value == v) return i;
        i++;
    } while (i <= 1);
    return -1;
}
