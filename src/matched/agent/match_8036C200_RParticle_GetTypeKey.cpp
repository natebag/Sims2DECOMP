// 0x8036C200 match_8036C200_RParticle_GetTypeKey (12b)
// 0x8036C200 RParticle::GetTypeKey (12b)
// TU: rparticle

struct TypeInfo {
    char pad[0x10];
    unsigned int m_key;
};

extern TypeInfo RParticle_typeInfo;

struct RParticle {
    unsigned int GetTypeKey() const;
};

unsigned int RParticle::GetTypeKey() const {
    return RParticle_typeInfo.m_key;
}
