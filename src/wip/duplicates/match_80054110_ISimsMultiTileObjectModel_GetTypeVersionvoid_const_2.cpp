// 0x80054110 (12 bytes)
class ISimsMultiTileObjectModel {
public:
    short GetTypeVersion() const;
};

extern char gISimsMultiTileObjectModelData[];

short ISimsMultiTileObjectModel::GetTypeVersion() const {
    return *(short*)(gISimsMultiTileObjectModelData + 0);
}
