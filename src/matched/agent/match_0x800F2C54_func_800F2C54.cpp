/* auto at 0x800F2C54 (40B) [li_two_call_chain] */

extern int inner1_800F2C54(int);
extern int inner2_800F2C54(int);
int func_800F2C54(void) {
    return inner2_800F2C54(inner1_800F2C54(8416));
}
