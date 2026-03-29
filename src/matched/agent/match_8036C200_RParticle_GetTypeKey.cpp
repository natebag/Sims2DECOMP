/* RParticle::GetTypeKey(void) const - 0x8036C200 (12 bytes) */
// TU: rparticle

extern unsigned int RParticle_typeInfo_key;

struct RParticle {
    unsigned int GetTypeKey() const;
};

unsigned int RParticle::GetTypeKey() const {
    return RParticle_typeInfo_key;
}
