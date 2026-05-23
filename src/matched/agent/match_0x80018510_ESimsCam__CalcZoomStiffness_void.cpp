// 0x80018510 ESimsCam::CalcZoomStiffness(void) (56 B)
struct ECamP { char _pad[0x20]; float f20; float f24; float f28; float f2c; };
struct ESimsCam { ECamP* m_params; char _pad[0x444]; float m_zoom; float CalcZoomStiffness(); };
extern float _s80018510_0(float, float, float, float, float);
float ESimsCam::CalcZoomStiffness() {
    return _s80018510_0(m_params->f20, m_params->f24, m_params->f28, m_params->f2c, m_zoom);
}
