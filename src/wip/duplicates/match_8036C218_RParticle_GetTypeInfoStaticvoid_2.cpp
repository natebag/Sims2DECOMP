// 0x8036C218 (12 bytes)
class RParticle {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __RParticle_TypeInfo;

struct TypeInfo* RParticle::GetTypeInfoStatic() const {
    return &__RParticle_TypeInfo;
}
