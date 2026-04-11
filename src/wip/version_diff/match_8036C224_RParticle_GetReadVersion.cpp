/* RParticle::GetReadVersion(void) - 0x8036C224 (12 bytes) */
// TU: rparticle

extern unsigned int RParticle_readVersion;

struct RParticle {
    static unsigned int GetReadVersion();
};

unsigned int RParticle::GetReadVersion() {
    return RParticle_readVersion;
}
