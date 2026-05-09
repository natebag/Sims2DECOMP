// 0x803C78AC FrameEffect::~FrameEffect(void) (52 B)
// PRAGMA_STUB: FrameEffect::~FrameEffect(void)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_FrameEffect_FrameEffect(char *self, int __in_chrg) {
    *(int **)(self + 16) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
