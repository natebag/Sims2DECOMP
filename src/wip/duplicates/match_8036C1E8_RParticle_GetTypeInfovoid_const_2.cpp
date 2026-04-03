// 0x8036C1E8 (12 bytes)
class RParticle {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __RParticle_TypeInfo;

struct TypeInfo* RParticle::GetTypeInfo() const {
    return &__RParticle_TypeInfo;
}
