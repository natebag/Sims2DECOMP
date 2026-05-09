// 0x801bd888 ITBTarget::UpdateIntroThoughtBalloon(void) (108B)
// Per-frame fade-decrement with NaN-loose `!(>)` early-out (ble) and `!(<)` late-out (bge).
// Constants: -60.0 (lower bound), 0.0333333351 (1/30 step), 0.0 (zero crossing).

class ITBTarget {
public:
    char pad[0x88];
    int m_field88;
    char pad2[8];
    int m_field94;
    int m_field98;
    float m_field9c;
    void HideIntroThoughtBalloon();
    void UpdateIntroThoughtBalloon();
};

void ITBTarget::UpdateIntroThoughtBalloon() {
    float val = m_field9c;
    if (!(val > -60.0f)) return;
    int flag = m_field88;
    val -= 0.0333333351f;
    m_field9c = val;
    if (flag == 0) return;
    if (m_field94 != 0) return;
    if (!(val < 0.0f)) return;
    HideIntroThoughtBalloon();
}
