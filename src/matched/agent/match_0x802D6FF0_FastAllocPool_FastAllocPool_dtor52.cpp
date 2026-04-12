// 0x802D6FF0 FastAllocPool_FastAllocPool_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_FastAllocPool_FastAllocPool(char *self, int __in_chrg) {
    *(int **)(self + 20) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
