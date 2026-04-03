// 0x80054128 (12 bytes)
class ISimsMultiTileObjectModel {
public:
    short GetReadVersion() const;
};

extern char gISimsMultiTileObjectModelData[];

short ISimsMultiTileObjectModel::GetReadVersion() const {
    return *(short*)(gISimsMultiTileObjectModelData + 0);
}
