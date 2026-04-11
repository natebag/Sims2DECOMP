// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_UIButtonImages_UIButtonImages(char *self, int __in_chrg) {
    *(int **)(self + 176) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
