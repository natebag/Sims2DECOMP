// 0x8036C20C RParticle::GetTypeVersion (12B) const
struct VerBlock_RParticle { unsigned short ver[256]; };
extern VerBlock_RParticle g_RParticle_TypeVersion[3];
struct RParticle_GTV { unsigned short GetTypeVersion() const; };
unsigned short RParticle_GTV::GetTypeVersion() const { return g_RParticle_TypeVersion[0].ver[0]; }
