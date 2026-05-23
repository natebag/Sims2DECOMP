// 0x800184D8 ESimsCam::CalcRotationStiffness(void) (56 B)
struct ECamP { char _pad[0x18]; float f18; float f1c; char _pad2[0x8]; float f28; float f2c; };
struct ESimsCam { ECamP* m_params; char _pad[0x444]; float m_zoom; float CalcRotationStiffness(); };
extern float _s800184D8_0(float, float, float, float, float);
float ESimsCam::CalcRotationStiffness() {
    return _s800184D8_0(m_params->f18, m_params->f1c, m_params->f28, m_params->f2c, m_zoom);
}
