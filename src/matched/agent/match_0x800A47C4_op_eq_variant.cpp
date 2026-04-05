int BS2_compare(void *, void *, int, int);

int op_eq_BString2(void *a, void *b) {
    return !BS2_compare(a, b, 0, -1);
}
