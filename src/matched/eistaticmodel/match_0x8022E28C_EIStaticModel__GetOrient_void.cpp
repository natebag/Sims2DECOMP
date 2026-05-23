// 0x8022E28C EIStaticModel::GetOrient(void) (8 B)
struct EIStaticModel { char _pad[192]; unsigned m_arr[1]; unsigned* GetOrient(); };
unsigned* EIStaticModel::GetOrient() { return m_arr; }
