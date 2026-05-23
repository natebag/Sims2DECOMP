// 0x8022F588 EIStaticSubModel::ModifyColor(unsigned) (8 B)
struct EIStaticSubModel { char _pad[0x94]; unsigned m_field; void ModifyColor(unsigned); };
void EIStaticSubModel::ModifyColor(unsigned val) { m_field = val; }
