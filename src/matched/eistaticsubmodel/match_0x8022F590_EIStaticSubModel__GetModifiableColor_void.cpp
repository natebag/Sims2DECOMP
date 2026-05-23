// 0x8022F590 EIStaticSubModel::GetModifiableColor(void) (8 B)
struct EIStaticSubModel { char _pad[0x94]; unsigned m_field; unsigned GetModifiableColor(); };
unsigned EIStaticSubModel::GetModifiableColor() { return m_field; }
