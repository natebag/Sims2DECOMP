// 0x80058820 MoviePlayerEndgameMovieState::MoviePlayerEndgameMovieState(int) (56b)

extern int g_vtable_80058820[8];

class StateCtorS {
public:
    int m_param;
    int m_field4;
    int m_field8;
    int m_fieldC;
    int m_field10;
    int m_field14;
    int *m_vtable;
    StateCtorS(int param);
};

StateCtorS::StateCtorS(int param) {
    m_param = param;
    m_field14 = 1;
    m_vtable = g_vtable_80058820;
    m_field4 = -1;
    m_field8 = 0;
    m_fieldC = -1;
    m_field10 = 0;
}
