// 0x80054110 (12 bytes)
// TU: iobject
class ISimsMultiTileObjectModel {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short ISimsMultiTileObjectModel_typeInfo[];

unsigned short ISimsMultiTileObjectModel::GetTypeVersion() const {
    return ISimsMultiTileObjectModel_typeInfo[10];
}
