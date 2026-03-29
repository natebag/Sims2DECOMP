// 0x80226F1C (12 bytes)
class EIAmbLight {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EIAmbLight_TypeInfo;

struct TypeInfo* EIAmbLight::GetTypeInfo() const {
    return &__EIAmbLight_TypeInfo;
}
