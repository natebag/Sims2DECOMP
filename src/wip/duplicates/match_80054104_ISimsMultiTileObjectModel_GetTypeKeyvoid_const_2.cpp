// 0x80054104 (12 bytes)
class ISimsMultiTileObjectModel {
public:
    const char* GetTypeKey() const;
};

extern char gISimsMultiTileObjectModelData[];

const char* ISimsMultiTileObjectModel::GetTypeKey() const {
    return *(const char**)(gISimsMultiTileObjectModelData + 0);
}
