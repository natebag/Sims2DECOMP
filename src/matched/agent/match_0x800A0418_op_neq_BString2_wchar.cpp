/* op_neq_BString2_wchar at 0x800A0418 (56B) */

extern int StrCmp_0x800A0418(int, int, int, int);

int op_neq_BString2_wchar(int a, int b) {
    int r = StrCmp_0x800A0418(a, b, 0, 1);
    if (r != 0) return 1;
    return 0;
}
