// 0x8022B848 (12 bytes)
class EISpotLight {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EISpotLight_TypeInfo;

struct TypeInfo* EISpotLight::GetTypeInfoStatic() const {
    return &__EISpotLight_TypeInfo;
}
