// 0x800540F8 (12 bytes)
class ISimsMultiTileObjectModel {
public:
    const char* GetTypeName() const;
};

extern char gISimsMultiTileObjectModelData[];

const char* ISimsMultiTileObjectModel::GetTypeName() const {
    return *(const char**)(gISimsMultiTileObjectModelData + 0);
}
