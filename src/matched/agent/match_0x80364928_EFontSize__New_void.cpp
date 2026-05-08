/* EFontSize__New_void at 0x80364928 (40B) — auto-matched [li_two_call_chain] */

extern int inner1_80364928(int);
extern int inner2_80364928(int);
int func_80364928(void) {
    return inner2_80364928(inner1_80364928(44));
}
