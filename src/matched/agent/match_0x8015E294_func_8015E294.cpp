/* auto at 0x8015E294 (40B) [li_two_call_chain] */

extern int inner1_8015E294(int);
extern int inner2_8015E294(int);
int func_8015E294(void) {
    return inner2_8015E294(inner1_8015E294(36));
}
