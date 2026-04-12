// 0x803A0CD8 LoadingScreenFadeOutState_LoadingScreenFadeOutState_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_LoadingScreenFadeOutState_LoadingScreenFadeOutState(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
