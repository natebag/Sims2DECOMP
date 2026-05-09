// 0x8000FED4 AptShaderWord::AptShaderWord (136B)

extern float g_shaderConst1[1] __attribute__((section(".data")));
extern float g_shaderConst2[1] __attribute__((section(".data")));

class AptShaderWord {
    float m_field_000;
    float m_field_004;
    float m_field_008;
    float m_field_00C;
    unsigned int m_field_010;
    unsigned int m_field_014;
    unsigned int m_field_018;
    unsigned int m_field_01C;
    unsigned int m_field_020;
    unsigned int m_field_024;
    unsigned int m_field_028;
    unsigned int m_vtable;
    float m_field_030;
public:
    AptShaderWord();
};

AptShaderWord::AptShaderWord() {
    m_vtable = 0x8046AD88;
    m_field_018 = 0;
    m_field_000 = 0.0f;
    m_field_008 = 0.0f;
    m_field_00C = 0.0f;
    m_field_010 = 0;
    m_field_014 = 0;
    
    float f1 = g_shaderConst1[0];
    m_field_01C = *(unsigned int*)&f1;
    m_field_020 = *(unsigned int*)&f1;
    
    float f2 = g_shaderConst2[0];
    m_field_024 = *(unsigned int*)&f2;
    m_field_028 = *(unsigned int*)&f2;
    
    m_field_030 = f2;
    m_vtable = 0x8046AD58;
}
