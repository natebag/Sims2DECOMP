// 0x8022F910 EIStaticSubModel::GetBoundSphere(void) (8B)
struct EIStaticSubModel { char _pad[0x80]; char m_boundSphere[1]; char* GetBoundSphere(); };
char* EIStaticSubModel::GetBoundSphere() { return m_boundSphere; }
