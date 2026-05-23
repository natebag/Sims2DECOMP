// 0x800BC98C HouseImpl::GetSizeScoreCurve(void) (8 B)
struct HouseImpl { char _pad[0x1c]; unsigned m_field; unsigned GetSizeScoreCurve(); };
unsigned HouseImpl::GetSizeScoreCurve() { return m_field; }
