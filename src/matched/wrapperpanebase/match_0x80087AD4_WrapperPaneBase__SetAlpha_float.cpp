// 0x80087AD4 WrapperPaneBase::SetAlpha(float) (8 B)
struct WrapperPaneBase { char _pad[0x30]; float m_alpha; void SetAlpha(float); };
void WrapperPaneBase::SetAlpha(float val) { m_alpha = val; }
