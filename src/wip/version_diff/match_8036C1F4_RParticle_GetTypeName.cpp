// 0x8036C1F4 RParticle::GetTypeName (12b)
// TU: rparticle

struct TypeInfo {
    char pad[0x0C];
    const char* m_name;
};

extern TypeInfo RParticle_typeInfo;

struct RParticle {
    const char* GetTypeName() const;
};

const char* RParticle::GetTypeName() const {
    return RParticle_typeInfo.m_name;
}
