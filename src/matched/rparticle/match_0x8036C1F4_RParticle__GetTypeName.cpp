// 0x8036C1F4 RParticle::GetTypeName (12B) const
extern char* g_RParticle_TypeName[3];
struct RParticle_GTN { const char* GetTypeName() const; };
const char* RParticle_GTN::GetTypeName() const { return g_RParticle_TypeName[0]; }
