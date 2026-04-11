/* RParticle::GetTypeVersion(void) const - 0x8036C20C (12 bytes) */
// TU: rparticle

extern unsigned int RParticle_typeInfo_version;

struct RParticle {
    unsigned int GetTypeVersion() const;
};

unsigned int RParticle::GetTypeVersion() const {
    return RParticle_typeInfo_version;
}
