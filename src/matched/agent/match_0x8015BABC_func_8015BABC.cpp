/* auto at 0x8015BABC (40B) [li_two_call_chain] */

extern int inner1_8015BABC(int);
extern int inner2_8015BABC(int);
int func_8015BABC(void) {
    return inner2_8015BABC(inner1_8015BABC(36));
}
