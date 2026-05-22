// 0x800169E8 ESimsCam::SetFov(float) (52B)

struct CamData {
    char pad[0x28];
    float m_28;
    float m_2C;
    char pad30[0x30];
    float m_60;
    float m_64;
};

class ESimsCam {
public:
    CamData* m_0;
    char pad4[0x448 - 4];
    float m_448;
    void SetFov(float arg);
};

void ESimsCam::SetFov(float arg) {
    CamData* s = m_0;
    float range = s->m_64 - s->m_60;
    float numer = (arg - s->m_60) * (s->m_2C - s->m_28) + s->m_28 * range;
    m_448 = numer / range;
}
