// 0x80322AF4 REffectsAttachment::GetReadVersion (12B)
struct RVBlock_REffectsAttachment { unsigned short ver[256]; };
extern RVBlock_REffectsAttachment g_REffectsAttachment_ReadVersion[3];
struct REffectsAttachment_GRV { unsigned short GetReadVersion(); };
unsigned short REffectsAttachment_GRV::GetReadVersion() { return g_REffectsAttachment_ReadVersion[0].ver[0]; }
