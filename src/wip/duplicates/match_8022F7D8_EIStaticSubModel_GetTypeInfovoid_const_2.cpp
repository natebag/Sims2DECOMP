// 0x8022F7D8 (12 bytes)
class EIStaticSubModel {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __EIStaticSubModel_TypeInfo;

struct TypeInfo* EIStaticSubModel::GetTypeInfo() const {
    return &__EIStaticSubModel_TypeInfo;
}
