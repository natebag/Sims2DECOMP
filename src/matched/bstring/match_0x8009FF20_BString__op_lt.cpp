extern "C" int BString_compare(void* a, void* b, int flags, int dir);
int BString_op_lt(void* a, void* b) {
    int r = BString_compare(a, b, 0, -1);
    return (unsigned)r >> 31;
}
