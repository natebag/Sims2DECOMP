// 0x8031B494 ERModel::GetLightPos(void) (8 B)
struct ERModel { char _pad[324]; unsigned m_arr[1]; unsigned* GetLightPos(); };
unsigned* ERModel::GetLightPos() { return m_arr; }
