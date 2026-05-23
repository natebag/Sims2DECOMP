extern "C" int BString2_compare(void* a, void* b, int flags, int dir);
int BString2_op_lt(void* a, void* b) {
    int r = BString2_compare(a, b, 0, -1);
    return (unsigned)r >> 31;
}
