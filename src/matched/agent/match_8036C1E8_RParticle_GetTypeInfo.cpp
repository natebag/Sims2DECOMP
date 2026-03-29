/* RParticle::GetTypeInfo(void) const - 0x8036C1E8 (12 bytes) */
// TU: rparticle

struct TypeInfo;

extern TypeInfo RParticle_typeInfo;

struct RParticle {
    const TypeInfo* GetTypeInfo() const;
};

const TypeInfo* RParticle::GetTypeInfo() const {
    return &RParticle_typeInfo;
}
