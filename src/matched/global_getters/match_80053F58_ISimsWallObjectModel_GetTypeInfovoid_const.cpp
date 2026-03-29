// 0x80053F58 (12 bytes)
class ISimsWallObjectModel {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ISimsWallObjectModel_TypeInfo;

struct TypeInfo* ISimsWallObjectModel::GetTypeInfo() const {
    return &__ISimsWallObjectModel_TypeInfo;
}
