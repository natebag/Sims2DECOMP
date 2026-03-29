// 0x8022E0A0 (12 bytes)
class EIStaticModel {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EIStaticModel_TypeInfo;

struct TypeInfo* EIStaticModel::GetTypeInfoStatic() const {
    return &__EIStaticModel_TypeInfo;
}
