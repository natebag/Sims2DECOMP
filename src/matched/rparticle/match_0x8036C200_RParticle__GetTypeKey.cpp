// 0x8036C200 RParticle::GetTypeKey (12B) const
extern int g_RParticle_TypeKey[3];
struct RParticle_GTK { int GetTypeKey() const; };
int RParticle_GTK::GetTypeKey() const { return g_RParticle_TypeKey[0]; }
