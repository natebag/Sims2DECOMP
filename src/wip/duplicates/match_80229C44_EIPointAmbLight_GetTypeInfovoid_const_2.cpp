// 0x80229C44 (12 bytes)
class EIPointAmbLight {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EIPointAmbLight_TypeInfo;

struct TypeInfo* EIPointAmbLight::GetTypeInfo() const {
    return &__EIPointAmbLight_TypeInfo;
}
