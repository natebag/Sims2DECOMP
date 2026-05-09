// 0x801dfb1c RMDTarget::Update(void) (124B)
// 3 int gates → NaN-loose `>` zero-cross gate (ble inverse) → step decrement →
// NaN-strict `<=` cmp (cror so,eq,lt; bns) → set flag + tail-call StartHideTween.

class RMDTarget {
public:
    char pad[0x84];
    int m_field84;
    int m_field88;
    char pad2[0x1c];
    float m_fielda8;
    int m_fieldac;
    void StartHideTween();
    void Update();
};

extern float g_rmdStep;

void RMDTarget::Update() {
    if (m_field84 == 0) return;
    if (m_field88 != 2) return;
    if (m_fieldac != 0) return;
    if (m_fielda8 > 0.0f) {
        m_fielda8 -= g_rmdStep;
        if (m_fielda8 <= 0.0f) {
            m_fieldac = 1;
            StartHideTween();
        }
    }
}
