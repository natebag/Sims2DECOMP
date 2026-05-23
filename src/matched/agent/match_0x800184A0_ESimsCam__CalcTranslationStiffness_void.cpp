// 0x800184A0 ESimsCam::CalcTranslationStiffness(void) (56 B)
struct ECamP { char _pad[0x10]; float f10; float f14; char _pad2[0x10]; float f28; float f2c; };
struct ESimsCam { ECamP* m_params; char _pad[0x444]; float m_zoom; float CalcTranslationStiffness(); };
extern float _s800184A0_0(float, float, float, float, float);
float ESimsCam::CalcTranslationStiffness() {
    return _s800184A0_0(m_params->f10, m_params->f14, m_params->f28, m_params->f2c, m_zoom);
}
