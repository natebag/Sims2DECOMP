// 0x8022F808 (12 bytes)
class EIStaticSubModel {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __EIStaticSubModel_TypeInfo;

struct TypeInfo* EIStaticSubModel::GetTypeInfoStatic() const {
    return &__EIStaticSubModel_TypeInfo;
}
