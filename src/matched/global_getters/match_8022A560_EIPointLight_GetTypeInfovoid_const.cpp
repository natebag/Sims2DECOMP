// 0x8022A560 (12 bytes)
class EIPointLight {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EIPointLight_TypeInfo;

struct TypeInfo* EIPointLight::GetTypeInfo() const {
    return &__EIPointLight_TypeInfo;
}
