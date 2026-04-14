// 0x8031B2B0 ERModel::GetTypeName (12B) const
extern char* g_ERModel_TypeName[3];
struct ERModel_GTN { const char* GetTypeName() const; };
const char* ERModel_GTN::GetTypeName() const { return g_ERModel_TypeName[0]; }
