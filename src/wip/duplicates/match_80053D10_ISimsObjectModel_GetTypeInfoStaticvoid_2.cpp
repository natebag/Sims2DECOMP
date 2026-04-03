// 0x80053D10 (12 bytes)
class ISimsObjectModel {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ISimsObjectModel_TypeInfo;

struct TypeInfo* ISimsObjectModel::GetTypeInfoStatic() const {
    return &__ISimsObjectModel_TypeInfo;
}
