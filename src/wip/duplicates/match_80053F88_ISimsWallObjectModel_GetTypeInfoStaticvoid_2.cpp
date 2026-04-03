// 0x80053F88 (12 bytes)
class ISimsWallObjectModel {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ISimsWallObjectModel_TypeInfo;

struct TypeInfo* ISimsWallObjectModel::GetTypeInfoStatic() const {
    return &__ISimsWallObjectModel_TypeInfo;
}
