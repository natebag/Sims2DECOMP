// 0x8005411C (12 bytes)
class ISimsMultiTileObjectModel {
public:
    struct TypeInfo* GetTypeInfoStatic() const;
};

struct TypeInfo;
extern TypeInfo __ISimsMultiTileObjectModel_TypeInfo;

struct TypeInfo* ISimsMultiTileObjectModel::GetTypeInfoStatic() const {
    return &__ISimsMultiTileObjectModel_TypeInfo;
}
