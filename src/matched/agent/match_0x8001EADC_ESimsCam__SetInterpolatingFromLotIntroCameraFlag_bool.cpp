// 0x8001EADC ESimsCam::SetInterpolatingFromLotIntroCameraFlag(bool) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x568]; int m_interpLotIntro; void SetInterpolatingFromLotIntroCameraFlag(int); };
void ESimsCam::SetInterpolatingFromLotIntroCameraFlag(int v) { m_interpLotIntro = v; }
