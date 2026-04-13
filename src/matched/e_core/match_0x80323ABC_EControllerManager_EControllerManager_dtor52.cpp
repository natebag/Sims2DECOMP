// FLAGS: -fno-schedule-insns
// 0x80323ABC (52B)
extern int VT[];
void del_fn(void *);
void d_EControllerManager_EControllerManager(char *self, int __in_chrg) {
    *(int **)(self + 32) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
