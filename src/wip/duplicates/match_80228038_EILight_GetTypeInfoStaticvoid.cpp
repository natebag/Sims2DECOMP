// 0x80228038 (12 bytes)
class EILight {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EILight_TypeInfo;

struct TypeInfo* EILight::GetTypeInfoStatic() const {
    return &__EILight_TypeInfo;
}
