/* RParticle::GetTypeName(void) const - 0x8036C1F4 (12 bytes) */
// TU: rparticle

extern char RParticle_typeInfo_name;

struct RParticle {
    const char* GetTypeName() const;
};

const char* RParticle::GetTypeName() const {
    return &RParticle_typeInfo_name;
}
