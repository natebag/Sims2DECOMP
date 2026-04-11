// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_UI3D_UI3DRecord_UI3DRecord(char *self, int __in_chrg) {
    *(int **)(self + 36) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
