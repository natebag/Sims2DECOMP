// 0x80078B74 CUnlockDisplay::SetDirectLight(float, float, float, int) (92B)
// TRIAGE: Held during fleet git-coordination — analysis only.

struct Light {
    int r;
    int g;
    int b;
    char pad[12];
};

class CUnlockDisplay {
public:
    char pad_000[864];
    Light m_lights[4];
    char pad_3C0[128];
    int  m_count;
    void SetDirectLight(float r, float g, float b, int idx);
};

void CUnlockDisplay::SetDirectLight(float r, float g, float b, int idx) {
    if (idx > 3) return;
    int newCount = idx + 1;
    if (newCount > m_count) m_count = newCount;

    float buf[3];
    buf[0] = r;
    buf[1] = g;
    buf[2] = b;
    int* ibuf = (int*)buf;
    m_lights[idx].r = ibuf[0];
    m_lights[idx].b = ibuf[2];
    m_lights[idx].g = ibuf[1];
}
