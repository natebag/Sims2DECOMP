// 0x8036C1E8 RParticle::GetTypeInfo (12B) const
struct TypeInfo_RParticle { char data[256]; };
extern TypeInfo_RParticle g_RParticle_TypeInfo[3];
struct RParticle_GTI { TypeInfo_RParticle* GetTypeInfo() const; };
TypeInfo_RParticle* RParticle_GTI::GetTypeInfo() const { return &g_RParticle_TypeInfo[0]; }
