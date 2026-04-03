// 0x8022B818 (12 bytes)
class EISpotLight {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EISpotLight_TypeInfo;

struct TypeInfo* EISpotLight::GetTypeInfo() const {
    return &__EISpotLight_TypeInfo;
}
