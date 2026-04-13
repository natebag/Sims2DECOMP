// 0x80359DD8 DepthOfFieldNGC_DepthOfFieldNGC_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_DepthOfFieldNGC_DepthOfFieldNGC(char *self, int __in_chrg) {
    *(int **)(self + 16) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
