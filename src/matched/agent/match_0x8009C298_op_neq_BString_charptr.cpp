extern "C" int compare_str(void* a, void* b, int flags);
int op_neq_BString_charptr(void* a, void* b) {
    if (compare_str(a, b, 0) != 0) return 1;
    return 0;
}
