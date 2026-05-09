// 0x8006a494 SAnimator2::getDeltaDirFromDesiredDir(float) (116B)
// Angle-wrap into (-pi, pi] via two while-loops + fabs deadzone clamp at eps.
// NaN-loose `ble/bgt` first-loop, NaN-loose `bge/blt` second-loop, NaN-loose `bgelr`
// final deadzone test. fabs result lands in f13 — preserves delta in f1 across cmp.

extern "C" float fabsf(float);

class SAnimator2 {
public:
    char pad[0x30];
    float m_field30;
    float getDeltaDirFromDesiredDir(float desired);
};

float SAnimator2::getDeltaDirFromDesiredDir(float desired) {
    float delta = desired - m_field30;
    while (delta > 3.14159274f) delta -= 6.28318548f;
    while (delta < -3.14159274f) delta += 6.28318548f;
    if (!(fabsf(delta) < 0.0001f)) return delta;
    return 0.0f;
}
