// 0x8022F590 EIStaticSubModel::GetModifiableColor(void) (8B)
struct EIStaticSubModel { char _pad[0x94]; unsigned int m_color; unsigned int GetModifiableColor(); };
unsigned int EIStaticSubModel::GetModifiableColor() { return m_color; }
