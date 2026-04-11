// 0x800184D8 (56B)
// ESimsCam::CalcRotationStiffness(void) const

struct ESimsCamData {
    char _pad[24];
    float m_field18;   // +0x18
    float m_field1C;   // +0x1C
    char _pad2[4];
    float m_field24;   // +0x24
    float m_field28;   // +0x28
    float m_field2C;   // +0x2C
};

struct ESimsCam {
    ESimsCamData* m_pData;  // +0x00
    char _pad[1092];
    float m_stiffnessValue; // +0x448
};

extern float CalcStiffness(float f1, float f2, float f3, float f4, float f5);

float ESimsCam_CalcRotationStiffness(ESimsCam* this_) {
    ESimsCamData* pData = this_->m_pData;
    float f5 = this_->m_stiffnessValue;
    float f4 = pData->m_field2C;
    float f1 = pData->m_field18;
    float f2 = pData->m_field1C;
    float f3 = pData->m_field28;
    return CalcStiffness(f1, f2, f3, f4, f5);
}
