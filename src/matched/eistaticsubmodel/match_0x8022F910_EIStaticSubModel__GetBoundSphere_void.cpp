// 0x8022F910 EIStaticSubModel::GetBoundSphere(void) (8 B)
struct EIStaticSubModel { char _pad[128]; unsigned m_arr[1]; unsigned* GetBoundSphere(); };
unsigned* EIStaticSubModel::GetBoundSphere() { return m_arr; }
