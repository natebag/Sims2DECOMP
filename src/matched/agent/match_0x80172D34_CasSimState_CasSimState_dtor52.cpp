// 0x80172D34 CasSimState_CasSimState_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_CasSimState_CasSimState(char *self, int __in_chrg) {
    *(int **)(self + 4) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
