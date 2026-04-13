// FLAGS: -fno-schedule-insns
// 0x803BAA60 (52B)
extern int VT[];
void del_fn(void *);
void d_AptVar_AptVar(char *self, int __in_chrg) {
    *(int **)(self + 8) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
