// 0x803A0254 MoviePlayerEndgameMovieState::~MoviePlayerEndgameMovieState (52b)
// FLAGS: -fno-elide-constructors

extern int MPE_VT[];
void del_fn(void *);
void d_MoviePlayerEndgameMovieState_MoviePlayerEndgameMovieState(char *self, int __in_chrg) {
    *(int **)(self + 24) = MPE_VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
