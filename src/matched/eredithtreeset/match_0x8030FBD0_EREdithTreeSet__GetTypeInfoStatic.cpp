// 0x8030FBD0 EREdithTreeSet::GetTypeInfoStatic (12B)
struct TypeInfo_EREdithTreeSet { char data[256]; };
extern TypeInfo_EREdithTreeSet g_EREdithTreeSet_TypeInfo[3];
TypeInfo_EREdithTreeSet* EREdithTreeSet_GetTypeInfoStatic() { return &g_EREdithTreeSet_TypeInfo[0]; }
