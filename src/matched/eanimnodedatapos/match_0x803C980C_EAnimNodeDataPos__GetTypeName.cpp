// 0x803C980C EAnimNodeDataPos::GetTypeName (12B) const
extern char* g_EAnimNodeDataPos_TypeName[3];
struct EAnimNodeDataPos_GTN { const char* GetTypeName() const; };
const char* EAnimNodeDataPos_GTN::GetTypeName() const { return g_EAnimNodeDataPos_TypeName[0]; }
