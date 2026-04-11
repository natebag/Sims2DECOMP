// FLAGS: -fno-schedule-insns
// 0x803C978C (52B)
extern int VT[];
void del_fn(void *);
void d_EAnimNodeDataPos_EAnimNodeDataPos(char *self, int __in_chrg) {
    *(int **)self = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
