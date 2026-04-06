extern "C" int BString2_compare_wchar(void* a, void* b, int flags, int dir);
int op_lt_BString2_wchar(void* a, void* b) {
    int r = BString2_compare_wchar(a, b, 0, 1);
    return (unsigned)r >> 31;
}
