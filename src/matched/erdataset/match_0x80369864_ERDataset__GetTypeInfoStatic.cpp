// 0x80369864 ERDataset::GetTypeInfoStatic (12B)
struct TypeInfo_ERDataset { char data[256]; };
extern TypeInfo_ERDataset g_ERDataset_TypeInfo[3];
TypeInfo_ERDataset* ERDataset_GetTypeInfoStatic() { return &g_ERDataset_TypeInfo[0]; }
