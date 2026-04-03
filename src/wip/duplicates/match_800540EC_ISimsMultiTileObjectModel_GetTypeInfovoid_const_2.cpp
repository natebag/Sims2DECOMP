// 0x800540EC (12 bytes)
class ISimsMultiTileObjectModel {
public:
    struct TypeInfo* GetTypeInfo() const;
};

struct TypeInfo;
extern TypeInfo __ISimsMultiTileObjectModel_TypeInfo;

struct TypeInfo* ISimsMultiTileObjectModel::GetTypeInfo() const {
    return &__ISimsMultiTileObjectModel_TypeInfo;
}
