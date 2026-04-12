// 0x80054128 (12 bytes)
// TU: iobject
class ISimsMultiTileObjectModel {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short ISimsMultiTileObjectModel_typeInfo[];

unsigned short ISimsMultiTileObjectModel::GetReadVersion() const {
    return ISimsMultiTileObjectModel_typeInfo[11];
}
