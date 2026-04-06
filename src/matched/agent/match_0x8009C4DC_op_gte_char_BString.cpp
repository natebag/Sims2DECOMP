extern "C" int compare_lt(void* a, void* b);
int op_gte_char_BString(void* a, void* b) {
    return compare_lt(a, b) ^ 1;
}
