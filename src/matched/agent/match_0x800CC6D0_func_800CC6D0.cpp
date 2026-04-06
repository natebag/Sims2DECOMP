/* auto at 0x800CC6D0 (40B) [li_two_call_chain] */

extern int inner1_800CC6D0(int);
extern int inner2_800CC6D0(int);
int func_800CC6D0(void) {
    return inner2_800CC6D0(inner1_800CC6D0(204));
}
