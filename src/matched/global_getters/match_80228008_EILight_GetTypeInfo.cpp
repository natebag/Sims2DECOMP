// 0x80228008 (12 bytes)
class EILight {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EILight_TypeInfo;

struct TypeInfo* EILight::GetTypeInfo() const {
    return &__EILight_TypeInfo;
}
