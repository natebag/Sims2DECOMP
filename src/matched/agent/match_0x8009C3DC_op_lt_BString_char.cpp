extern "C" int BString_compare(void* a, void* b, int flags, int dir);
int op_lt_BString_char(void* a, void* b) {
    int r = BString_compare(a, b, 0, 1);
    return (unsigned)r >> 31;
}
