// 0x8022E070 (12 bytes)
class EIStaticModel {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EIStaticModel_TypeInfo;

struct TypeInfo* EIStaticModel::GetTypeInfo() const {
    return &__EIStaticModel_TypeInfo;
}
