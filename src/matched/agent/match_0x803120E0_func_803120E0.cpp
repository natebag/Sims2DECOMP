/* auto at 0x803120E0 (40B) [li_two_call_chain] */

extern int inner1_803120E0(int);
extern int inner2_803120E0(int);
int func_803120E0(void) {
    return inner2_803120E0(inner1_803120E0(20));
}
