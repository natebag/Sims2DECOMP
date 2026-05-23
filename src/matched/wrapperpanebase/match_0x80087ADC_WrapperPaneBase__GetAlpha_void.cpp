// 0x80087ADC WrapperPaneBase::GetAlpha(void) (8 B)
struct WrapperPaneBase { char _pad[0x30]; float m_alpha; float GetAlpha(); };
float WrapperPaneBase::GetAlpha() { return m_alpha; }
