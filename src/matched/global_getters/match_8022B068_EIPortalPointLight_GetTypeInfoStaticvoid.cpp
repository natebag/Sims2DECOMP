// 0x8022B068 (12 bytes)
class EIPortalPointLight {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EIPortalPointLight_TypeInfo;

struct TypeInfo* EIPortalPointLight::GetTypeInfoStatic() const {
    return &__EIPortalPointLight_TypeInfo;
}
