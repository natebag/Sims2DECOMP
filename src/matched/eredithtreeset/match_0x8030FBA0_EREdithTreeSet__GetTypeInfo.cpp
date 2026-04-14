// 0x8030FBA0 EREdithTreeSet::GetTypeInfo (12B) const
struct TypeInfo_EREdithTreeSet { char data[256]; };
extern TypeInfo_EREdithTreeSet g_EREdithTreeSet_TypeInfo[3];
struct EREdithTreeSet_GTI { TypeInfo_EREdithTreeSet* GetTypeInfo() const; };
TypeInfo_EREdithTreeSet* EREdithTreeSet_GTI::GetTypeInfo() const { return &g_EREdithTreeSet_TypeInfo[0]; }
