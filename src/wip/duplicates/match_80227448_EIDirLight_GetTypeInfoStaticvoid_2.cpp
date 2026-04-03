// 0x80227448 (12 bytes)
class EIDirLight {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EIDirLight_TypeInfo;

struct TypeInfo* EIDirLight::GetTypeInfoStatic() const {
    return &__EIDirLight_TypeInfo;
}
