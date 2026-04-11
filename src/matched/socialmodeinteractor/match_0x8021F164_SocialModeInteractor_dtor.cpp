// 0x8021F164 SocialModeInteractor::~SocialModeInteractor (52b)
// FLAGS: -fno-schedule-insns

extern int VT[];
void del_fn(void *);
void d_SocialModeInteractor(char *self, int __in_chrg) {
    *(int **)(self + 0x5C) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
