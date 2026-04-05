int BS2_compare2(void *, void *, int, int);

int op_eq_BString2_wchar(void *a, void *b) {
    return !BS2_compare2(a, b, 0, 1);
}
