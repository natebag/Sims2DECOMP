// 0x80322AE8 REffectsAttachment::GetTypeInfoStatic (12B)
struct TypeInfo_REffectsAttachment { char data[256]; };
extern TypeInfo_REffectsAttachment g_REffectsAttachment_TypeInfo[3];
TypeInfo_REffectsAttachment* REffectsAttachment_GetTypeInfoStatic() { return &g_REffectsAttachment_TypeInfo[0]; }
