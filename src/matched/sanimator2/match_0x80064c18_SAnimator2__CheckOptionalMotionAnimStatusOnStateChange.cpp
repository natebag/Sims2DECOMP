/* 0x80064c18 (104 bytes) - SAnimator2::CheckOptionalMotionAnimStatusOnStateChange(SAnimator2::eAnimState) */
class SAnimator2 {
public:
    char pad[0x2C];
    int m_field_02C;
    char pad2[0x61C - 0x2C - 4];
    int m_stateFlags;
    void CheckOptionalMotionAnimStatusOnStateChange_12_14();
    void CheckOptionalMotionAnimStatusOnStateChange_other();
    void CheckOptionalMotionAnimStatusOnStateChange_final();
    void CheckOptionalMotionAnimStatusOnStateChange(int state);
};

void SAnimator2::CheckOptionalMotionAnimStatusOnStateChange(int state) {
    unsigned int ustate = (unsigned int)state;
    if (ustate - 12 <= 2) {
        CheckOptionalMotionAnimStatusOnStateChange_12_14();
    } else {
        CheckOptionalMotionAnimStatusOnStateChange_other();
    }
    if (m_field_02C == 9 || m_field_02C == 0) {
        if (state != 9) {
            CheckOptionalMotionAnimStatusOnStateChange_final();
        }
    }
}
