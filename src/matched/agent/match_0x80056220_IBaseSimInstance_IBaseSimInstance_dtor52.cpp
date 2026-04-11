// 0x80056220 0 (52b)
// FLAGS: -fno-schedule-insns

extern int VT[];
void del_fn(void *);
void d_IBaseSimInstance_IBaseSimInstance(char *self, int __in_chrg) {
    *(int **)self = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
