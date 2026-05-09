/* ERFont__New_void at 0x80317790 (40B) — auto-matched [li_two_call_chain] */

extern int inner1_80317790(int);
extern int inner2_80317790(int);
int func_80317790(void) {
    return inner2_80317790(inner1_80317790(108));
}
