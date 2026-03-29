// 0x80053CE0 (12 bytes)
class ISimsObjectModel {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ISimsObjectModel_TypeInfo;

struct TypeInfo* ISimsObjectModel::GetTypeInfo() const {
    return &__ISimsObjectModel_TypeInfo;
}
