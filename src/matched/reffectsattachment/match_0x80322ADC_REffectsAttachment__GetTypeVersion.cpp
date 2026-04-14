// 0x80322ADC REffectsAttachment::GetTypeVersion (12B) const
struct VerBlock_REffectsAttachment { unsigned short ver[256]; };
extern VerBlock_REffectsAttachment g_REffectsAttachment_TypeVersion[3];
struct REffectsAttachment_GTV { unsigned short GetTypeVersion() const; };
unsigned short REffectsAttachment_GTV::GetTypeVersion() const { return g_REffectsAttachment_TypeVersion[0].ver[0]; }
