// 0x80322AB8 REffectsAttachment::GetTypeInfo (12B) const
struct TypeInfo_REffectsAttachment { char data[256]; };
extern TypeInfo_REffectsAttachment g_REffectsAttachment_TypeInfo[3];
struct REffectsAttachment_GTI { TypeInfo_REffectsAttachment* GetTypeInfo() const; };
TypeInfo_REffectsAttachment* REffectsAttachment_GTI::GetTypeInfo() const { return &g_REffectsAttachment_TypeInfo[0]; }
