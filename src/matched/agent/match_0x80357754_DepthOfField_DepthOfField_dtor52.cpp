// 0x80357754 DepthOfField_DepthOfField_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_DepthOfField_DepthOfField(char *self, int __in_chrg) {
    *(int **)(self + 16) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
