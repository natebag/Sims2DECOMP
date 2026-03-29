// 0x80229C74 (12 bytes)
class EIPointAmbLight {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EIPointAmbLight_TypeInfo;

struct TypeInfo* EIPointAmbLight::GetTypeInfoStatic() const {
    return &__EIPointAmbLight_TypeInfo;
}
