// 0x8022A590 (12 bytes)
class EIPointLight {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EIPointLight_TypeInfo;

struct TypeInfo* EIPointLight::GetTypeInfoStatic() const {
    return &__EIPointLight_TypeInfo;
}
