/* EThread__GetCallingThreadObject_void at 0x802D8568 (36B) — auto-matched [two_call_chain] */

extern int inner1_802D8568(void*);
extern int inner2_802D8568(int);
int func_802D8568(void *self) {
    return inner2_802D8568(inner1_802D8568(self));
}
