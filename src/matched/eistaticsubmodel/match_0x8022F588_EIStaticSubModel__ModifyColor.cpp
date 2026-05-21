// 0x8022F588 EIStaticSubModel::ModifyColor(unsigned int) (8B)
struct EIStaticSubModel { char _pad[0x94]; unsigned int m_color; void ModifyColor(unsigned int c); };
void EIStaticSubModel::ModifyColor(unsigned int c) { m_color = c; }
