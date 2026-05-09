// 0x80091018 (60B) LoadingScreenWaitingForLoadState::FaderStart(float t)
// Init Fader at this->m_holder + 168: flags=16, m_t=t, m_dur=t, m_invT=1/t,
// then mask flags to (flags & ~0x0E) | 1.

extern float g_oneF[4];   // 0x803D7F50 — [4] forces non-SDA absolute

struct Fader {
    float m_t;       // +0
    float m_invT;    // +4
    float m_dur;     // +8
    int m_flags;     // +12
};

struct FaderHolder {
    char _pad[168];
    Fader m_fader;
};

class LoadingScreenWaitingForLoadState {
public:
    char _pad[8];
    FaderHolder* m_holder;   // +8
    void FaderStart(float t);
};

void LoadingScreenWaitingForLoadState::FaderStart(float t)
{
    Fader* f = &m_holder->m_fader;
    f->m_flags = 16;
    f->m_dur = t;
    f->m_t = t;
    float invT = g_oneF[0] / t;
    f->m_flags = (f->m_flags & ~0x0E) | 1;
    f->m_invT = invT;
}
