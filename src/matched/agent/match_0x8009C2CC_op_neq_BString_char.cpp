/* op_neq_BString_char at 0x8009C2CC (56B) */

extern int StrCmp_0x8009C2CC(int, int, int, int);

int op_neq_BString_char(int a, int b) {
    int r = StrCmp_0x8009C2CC(a, b, 0, 1);
    if (r != 0) return 1;
    return 0;
}
