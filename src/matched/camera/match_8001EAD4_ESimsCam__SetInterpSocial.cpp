// 0x8001EAD4 (8 bytes) — stw r4, 0x564(r3); blr

class ESimsCam {
public:
    char _pad[0x564];
    int m_interpSocialFlag;

    void SetInterpolatingToOrFromSocialModeCameraFlag(bool val);
};

void ESimsCam::SetInterpolatingToOrFromSocialModeCameraFlag(bool val) {
    m_interpSocialFlag = val;
}
