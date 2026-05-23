// 0x8022E284 EIStaticModel::GetDrawMatrix(void) (8 B)
struct EIStaticModel { char _pad[128]; unsigned m_arr[1]; unsigned* GetDrawMatrix(); };
unsigned* EIStaticModel::GetDrawMatrix() { return m_arr; }
