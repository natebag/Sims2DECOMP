// 0x8022B038 (12 bytes)
class EIPortalPointLight {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EIPortalPointLight_TypeInfo;

struct TypeInfo* EIPortalPointLight::GetTypeInfo() const {
    return &__EIPortalPointLight_TypeInfo;
}
