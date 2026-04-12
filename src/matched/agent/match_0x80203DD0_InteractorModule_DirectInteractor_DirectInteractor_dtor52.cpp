// 0x80203DD0 InteractorModule_DirectInteractor_DirectInteractor_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_InteractorModule_DirectInteractor_DirectInteractor(char *self, int __in_chrg) {
    *(int **)(self + 92) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
