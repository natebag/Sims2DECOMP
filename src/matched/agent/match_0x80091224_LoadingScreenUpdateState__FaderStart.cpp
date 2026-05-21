// 0x80091224 LoadingScreenUpdateState::FaderStart(float) (64B)

extern char g_one_float_803D80F8[16];

class FaderSettings {
public:
    float m_0;
    float m_4;
    float m_8;
    int m_12;
};

class State {
public:
    char pad[168];
    FaderSettings fader;
};

class LoadingScreenUpdateState {
public:
    char pad[8];
    State* m_state;
    void FaderStart(float t);
};

void LoadingScreenUpdateState::FaderStart(float t) {
    State* s = m_state;
    FaderSettings* f = &s->fader;
    *(volatile int*)&f->m_12 = 16;
    f->m_8 = t;
    *(float*)((char*)s + 168) = t;
    int flags = f->m_12;
    *(float*)((char*)f + 4) = *(float*)g_one_float_803D80F8 / t;
    *(volatile int*)&f->m_12 = (flags & ~13) | 2;
}
