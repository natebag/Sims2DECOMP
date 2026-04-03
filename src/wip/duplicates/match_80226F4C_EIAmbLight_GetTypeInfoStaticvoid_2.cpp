// 0x80226F4C (12 bytes)
class EIAmbLight {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EIAmbLight_TypeInfo;

struct TypeInfo* EIAmbLight::GetTypeInfoStatic() const {
    return &__EIAmbLight_TypeInfo;
}
