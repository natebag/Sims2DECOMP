// 0x80048404 EIFloor::GetTypeName (12B) const
extern char* g_EIFloor_TypeName[3];
struct EIFloor_GTN { const char* GetTypeName() const; };
const char* EIFloor_GTN::GetTypeName() const { return g_EIFloor_TypeName[0]; }
