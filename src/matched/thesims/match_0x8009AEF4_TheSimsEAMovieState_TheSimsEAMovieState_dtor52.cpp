// 0x8009AEF4 TheSimsEAMovieState::~TheSimsEAMovieState (52b)
// FLAGS: -fno-schedule-insns

extern int VT[];
void del_fn(void *);
void d_TheSimsEAMovieState_TheSimsEAMovieState(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
