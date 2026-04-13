// FLAGS: -fno-schedule-insns
// 0x803B214C (52B)
extern int VT[];
void del_fn(void *);
void d_UIUserDrawCBTable_UserDrawCBTableRecord_UserDrawCBTableRecord(char *self, int __in_chrg) {
    *(int **)(self + 20) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
