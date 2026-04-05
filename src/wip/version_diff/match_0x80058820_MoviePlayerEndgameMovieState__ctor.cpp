// VERSION_DIFF: leaf constructor store ordering differs
/* MoviePlayerEndgameMovieState::MoviePlayerEndgameMovieState(int) at 0x80058820 (56B) */

extern int g_vtable_80058820[8];

struct StateCtorS {
    int m_param;
    int m_field4;
    int m_field8;
    int m_fieldC;
    int m_field10;
    int m_field14;
    int *m_vtable;
};

StateCtorS *StateCtor(StateCtorS *self, int param) {
    self->m_param = param;
    self->m_fieldC = -1;
    self->m_field10 = 0;
    self->m_field14 = 1;
    self->m_vtable = g_vtable_80058820;
    self->m_field4 = -1;
    self->m_field8 = 0;
    return self;
}
