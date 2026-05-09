// PRAGMA_STUB: ERAnim::New(void)
/* ERAnim__New_void at 0x80367FD4 (40B) — auto-matched [li_two_call_chain] */

extern int inner1_80367FD4(int);
extern int inner2_80367FD4(int);
int func_80367FD4(void) {
    return inner2_80367FD4(inner1_80367FD4(160));
}
