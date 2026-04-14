// 0x80369834 ERDataset::GetTypeInfo (12B) const
struct TypeInfo_ERDataset { char data[256]; };
extern TypeInfo_ERDataset g_ERDataset_TypeInfo[3];
struct ERDataset_GTI { TypeInfo_ERDataset* GetTypeInfo() const; };
TypeInfo_ERDataset* ERDataset_GTI::GetTypeInfo() const { return &g_ERDataset_TypeInfo[0]; }
