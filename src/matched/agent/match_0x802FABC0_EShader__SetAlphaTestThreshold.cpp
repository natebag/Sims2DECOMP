/* EShader::SetAlphaTestThreshold(float, int) at 0x802FABC0 (16B) */

struct ShaderParamSlot {
    char _pad[20];
    float m_alphaThreshold;
    char _pad2[40];
};

struct EShader {
    char pad[0x64];
    ShaderParamSlot m_paramSlots[1];

    void SetAlphaTestThreshold(float val, int index);
};

void EShader::SetAlphaTestThreshold(float val, int index) {
    m_paramSlots[index].m_alphaThreshold = val;
}
