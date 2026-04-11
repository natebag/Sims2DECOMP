/* auto at 0x802F1390 (40B) [li_two_call_chain] */

extern int inner1_802F1390(int);
extern int inner2_802F1390(int);
int func_802F1390(void) {
    return inner2_802F1390(inner1_802F1390(116));
}
