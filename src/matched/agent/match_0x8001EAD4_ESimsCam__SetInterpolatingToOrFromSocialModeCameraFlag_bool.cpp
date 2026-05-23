// 0x8001EAD4 ESimsCam::SetInterpolatingToOrFromSocialModeCameraFlag(bool) (8 B)
// FLAGS: -fno-schedule-insns
struct ESimsCam { char _pad[0x564]; int m_interpSocialMode; void SetInterpolatingToOrFromSocialModeCameraFlag(int); };
void ESimsCam::SetInterpolatingToOrFromSocialModeCameraFlag(int v) { m_interpSocialMode = v; }
