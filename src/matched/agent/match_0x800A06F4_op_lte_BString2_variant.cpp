int BS_gt(void *, void *);

int op_lte_charptr_BString(void *a, void *b) {
    return BS_gt(b, a) ^ 1;
}
