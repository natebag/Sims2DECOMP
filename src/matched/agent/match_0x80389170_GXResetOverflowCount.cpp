// 0x80389170 GXResetOverflowCount (16b)

extern int gGXOverflowCount;

int GXResetOverflowCount() {
    int old = gGXOverflowCount;
    gGXOverflowCount = 0;
    return old;
}
