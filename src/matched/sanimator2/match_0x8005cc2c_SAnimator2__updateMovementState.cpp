/* 0x8005cc2c (80 bytes) - SAnimator2::updateMovementState(void) */
class SAnimator2 {
public:
    char pad[0x10];
    int m_field_010;
    char pad1[4];
    int m_field_018;
    char pad2[0x61C - 0x18 - 4];
    int m_stateFlags;
    void updateMovementState(void);
};

extern "C" void updateMovementState_GT5(SAnimator2* self);
extern "C" void updateMovementState_EQ1(SAnimator2* self);
extern "C" void updateMovementState_Bit0(SAnimator2* self);

void SAnimator2::updateMovementState() {
    if (m_field_018 > 5) {
        updateMovementState_GT5(this);
    } else if (m_field_010 == 1) {
        updateMovementState_EQ1(this);
    } else if (m_stateFlags & 1) {
        updateMovementState_Bit0(this);
    }
}
