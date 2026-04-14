// 0x80053F64 ISimsWallObjectModel::GetTypeName (12B) const
extern char* g_ISimsWallObjectModel_TypeName[3];
struct ISimsWallObjectModel_GTN { const char* GetTypeName() const; };
const char* ISimsWallObjectModel_GTN::GetTypeName() const { return g_ISimsWallObjectModel_TypeName[0]; }
