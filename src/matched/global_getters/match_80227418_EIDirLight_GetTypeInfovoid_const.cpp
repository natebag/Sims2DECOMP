// 0x80227418 (12 bytes)
class EIDirLight {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EIDirLight_TypeInfo;

struct TypeInfo* EIDirLight::GetTypeInfo() const {
    return &__EIDirLight_TypeInfo;
}
