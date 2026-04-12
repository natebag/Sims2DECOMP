// 0x80053F94 (12 bytes)
// TU: iobject
class ISimsWallObjectModel {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short ISimsWallObjectModel_typeInfo[];

unsigned short ISimsWallObjectModel::GetReadVersion() const {
    return ISimsWallObjectModel_typeInfo[11];
}
