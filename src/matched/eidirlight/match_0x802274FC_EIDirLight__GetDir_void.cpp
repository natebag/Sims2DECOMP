// 0x802274FC EIDirLight::GetDir(void) (8 B)
struct EIDirLight { char _pad[172]; unsigned m_arr[1]; unsigned* GetDir(); };
unsigned* EIDirLight::GetDir() { return m_arr; }
