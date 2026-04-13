// FLAGS: -fno-schedule-insns
// 0x802D5864 (52B)
extern int VT[];
void del_fn(void *);
void d_ESyncObject_ESyncObject(char *self, int __in_chrg) {
    *(int **)self = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
