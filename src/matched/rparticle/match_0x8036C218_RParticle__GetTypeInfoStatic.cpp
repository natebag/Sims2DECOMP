// 0x8036C218 RParticle::GetTypeInfoStatic (12B)
struct TypeInfo_RParticle { char data[256]; };
extern TypeInfo_RParticle g_RParticle_TypeInfo[3];
TypeInfo_RParticle* RParticle_GetTypeInfoStatic() { return &g_RParticle_TypeInfo[0]; }
