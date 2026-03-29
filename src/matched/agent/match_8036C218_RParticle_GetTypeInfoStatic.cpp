/* RParticle::GetTypeInfoStatic(void) - 0x8036C218 (12 bytes) */
// TU: rparticle

struct TypeInfo;

extern TypeInfo RParticle_typeInfo;

struct RParticle {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* RParticle::GetTypeInfoStatic() {
    return &RParticle_typeInfo;
}
