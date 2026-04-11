// 0x800184A0 (56B)
// ESimsCam::CalcTranslationStiffness(void) const

struct ESimsCamData {
    char _pad[16];
    float m_field10;   // +0x10
    float m_field14;   // +0x14
    char _pad2[8];
    float m_field20;   // +0x20
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

float ESimsCam_CalcTranslationStiffness(ESimsCam* this_) {
    ESimsCamData* pData = this_->m_pData;
    float f5 = this_->m_stiffnessValue;
    float f4 = pData->m_field2C;
    float f1 = pData->m_field10;
    float f2 = pData->m_field14;
    float f3 = pData->m_field28;
    return CalcStiffness(f1, f2, f3, f4, f5);
}
