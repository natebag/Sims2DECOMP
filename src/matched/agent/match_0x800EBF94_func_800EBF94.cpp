/* auto at 0x800EBF94 (40B) [li_two_call_chain] */

extern int inner1_800EBF94(int);
extern int inner2_800EBF94(int);
int func_800EBF94(void) {
    return inner2_800EBF94(inner1_800EBF94(1748));
}
