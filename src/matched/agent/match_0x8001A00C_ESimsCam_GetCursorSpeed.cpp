// 0x8001A00C (48B) ESimsCam::GetCursorSpeed(void)
// Lerp between pData[+88] and pData[+92] by t=(offset-pData[+40])/(pData[+44]-pData[+40]).

struct ESimsCamData {
    char _pad[40];
    float m_fieldA;   // +0x28
    float m_fieldB;   // +0x2C
    char _pad2[40];
    float m_fieldC;   // +0x58
    float m_fieldD;   // +0x5C
};

struct ESimsCam {
    ESimsCamData* m_pData;  // +0x00
    char _pad[1092];
    float m_offset;   // +0x448
};

float ESimsCam_GetCursorSpeed(ESimsCam* self) {
    ESimsCamData* pData = self->m_pData;
    float offset = self->m_offset;
    float a = pData->m_fieldA;
    float b = pData->m_fieldB;
    float t = (offset - a) / (b - a);
    float c = pData->m_fieldC;
    float d = pData->m_fieldD;
    return t * (d - c) + c;
}
