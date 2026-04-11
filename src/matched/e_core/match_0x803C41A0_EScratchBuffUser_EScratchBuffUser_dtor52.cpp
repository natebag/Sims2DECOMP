// FLAGS: -fno-schedule-insns
// 0x803C41A0 (52B)
extern int VT[];
void del_fn(void *);
void d_EScratchBuffUser_EScratchBuffUser(char *self, int __in_chrg) {
    *(int **)self = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
