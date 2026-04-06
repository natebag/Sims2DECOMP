/* auto at 0x80056800 (40B) [li_two_call_chain] */

extern int inner1_80056800(int);
extern int inner2_80056800(int);
int func_80056800(void) {
    return inner2_80056800(inner1_80056800(968));
}
