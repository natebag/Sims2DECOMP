// 0x8006b4d0 SAnimator2::getSidestepIntensity(void) (92B)
// sin(angle)^2 with NaN-loose deadzone clamps via single-insn ble/bge.
// Tail-bl into sinf — float-arg passthrough.

extern "C" float sinf(float);

class SAnimator2 {
public:
    char pad[0x110];
    float m_field110;
    float getSidestepIntensity();
};

float SAnimator2::getSidestepIntensity() {
    float val = sinf(m_field110);
    val = val * val;
    if (val < 0.0001f) val = 0.0f;
    else if (val > 0.9999f) val = 1.0f;
    return val;
}
