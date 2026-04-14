// 0x80322AC4 REffectsAttachment::GetTypeName (12B) const
extern char* g_REffectsAttachment_TypeName[3];
struct REffectsAttachment_GTN { const char* GetTypeName() const; };
const char* REffectsAttachment_GTN::GetTypeName() const { return g_REffectsAttachment_TypeName[0]; }
