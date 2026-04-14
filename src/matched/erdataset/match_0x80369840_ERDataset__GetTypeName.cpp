// 0x80369840 ERDataset::GetTypeName (12B) const
extern char* g_ERDataset_TypeName[3];
struct ERDataset_GTN { const char* GetTypeName() const; };
const char* ERDataset_GTN::GetTypeName() const { return g_ERDataset_TypeName[0]; }
