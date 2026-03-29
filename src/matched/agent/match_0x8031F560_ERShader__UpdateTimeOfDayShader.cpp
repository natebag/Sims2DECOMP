/* ERShader::UpdateTimeOfDayShader(void) at 0x8031F560 (68B) */

struct ERShader {
    char pad_00[0x66];
    unsigned char m_field_066;  // 0x66
    unsigned char m_field_067;  // 0x67
    void SetShaderASyncForState(int);
    void UpdateTimeOfDayShader(void);
};

void ERShader::UpdateTimeOfDayShader(void) {
    unsigned int a = m_field_067;
    unsigned int b = m_field_066;
    unsigned int div = a / 15;
    int state = (b * 4 + div) & 0xFF;
    SetShaderASyncForState(state);
}
