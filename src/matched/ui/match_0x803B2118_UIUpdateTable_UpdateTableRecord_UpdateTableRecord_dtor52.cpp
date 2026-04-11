// FLAGS: -fno-schedule-insns
// 0x803B2118 (52B)
extern int VT[];
void del_fn(void *);
void d_UIUpdateTable_UpdateTableRecord_UpdateTableRecord(char *self, int __in_chrg) {
    *(int **)(self + 20) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
