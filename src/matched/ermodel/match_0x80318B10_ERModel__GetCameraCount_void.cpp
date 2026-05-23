// 0x80318B10 ERModel::GetCameraCount(void) (8 B)
struct ERModel { char _pad[0x12c]; unsigned m_field; unsigned GetCameraCount(); };
unsigned ERModel::GetCameraCount() { return m_field; }
