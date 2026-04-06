// 0x80058820 MoviePlayerEndgameMovieState::MoviePlayerEndgameMovieState (56b)
extern int MPEMS_vtable[];

struct MPEMS {
    int m_movieId;    // 0x00
    int m_field04;    // 0x04
    int m_field08;    // 0x08
    int m_field0C;    // 0x0C
    int m_field10;    // 0x10
    int m_field14;    // 0x14
    int* m_vtable18;  // 0x18
};

void MPEMS_ctor(MPEMS* self, int movieId) {
    self->m_movieId = movieId;
    self->m_field0C = -1;
    self->m_field10 = 0;
    self->m_field14 = 1;
    self->m_vtable18 = MPEMS_vtable;
    self->m_field04 = -1;
    self->m_field08 = 0;
}
