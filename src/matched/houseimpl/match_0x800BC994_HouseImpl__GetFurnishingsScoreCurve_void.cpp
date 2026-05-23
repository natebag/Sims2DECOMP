// 0x800BC994 HouseImpl::GetFurnishingsScoreCurve(void) (8 B)
struct HouseImpl { char _pad[0x20]; unsigned m_field; unsigned GetFurnishingsScoreCurve(); };
unsigned HouseImpl::GetFurnishingsScoreCurve() { return m_field; }
