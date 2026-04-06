extern "C" int BString2_compare(void* a, void* b, int flags);
int op_eq_BString2_wcharptr(void* a, void* b) {
    return BString2_compare(a, b, 0) == 0;
}
