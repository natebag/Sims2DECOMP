// 0x803C9800 EAnimNodeDataPos::GetTypeInfo (12B) const
struct TypeInfo_EAnimNodeDataPos { char data[256]; };
extern TypeInfo_EAnimNodeDataPos g_EAnimNodeDataPos_TypeInfo[3];
struct EAnimNodeDataPos_GTI { TypeInfo_EAnimNodeDataPos* GetTypeInfo() const; };
TypeInfo_EAnimNodeDataPos* EAnimNodeDataPos_GTI::GetTypeInfo() const { return &g_EAnimNodeDataPos_TypeInfo[0]; }
