// 0x80322AD0 REffectsAttachment::GetTypeKey (12B) const
extern int g_REffectsAttachment_TypeKey[3];
struct REffectsAttachment_GTK { int GetTypeKey() const; };
int REffectsAttachment_GTK::GetTypeKey() const { return g_REffectsAttachment_TypeKey[0]; }
