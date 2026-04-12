// 0x803A09E0 LiveModeInitState_LiveModeInitState_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_LiveModeInitState_LiveModeInitState(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
