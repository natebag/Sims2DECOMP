// FLAGS: -fno-schedule-insns
// 0x80364CF0 EMovie::~EMovie (52b)
// FLAGS: -fno-schedule-insns

extern int VT[];
void del_fn(void *);
void d_EMovie_EMovie(char *self, int __in_chrg) {
    *(int **)(self + 8) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
