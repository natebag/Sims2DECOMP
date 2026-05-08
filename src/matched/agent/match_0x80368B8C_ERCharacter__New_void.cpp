/* ERCharacter__New_void at 0x80368B8C (40B) — auto-matched [li_two_call_chain] */

extern int inner1_80368B8C(int);
extern int inner2_80368B8C(int);
int func_80368B8C(void) {
    return inner2_80368B8C(inner1_80368B8C(52));
}
