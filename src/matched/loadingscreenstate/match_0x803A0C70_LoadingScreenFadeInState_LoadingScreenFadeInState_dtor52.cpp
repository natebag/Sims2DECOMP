// 0x803A0C70 LoadingScreenFadeInState_LoadingScreenFadeInState_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_LoadingScreenFadeInState_LoadingScreenFadeInState(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
