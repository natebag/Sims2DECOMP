// 0x80053F7C (12 bytes)
// TU: iobject
class ISimsWallObjectModel {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short ISimsWallObjectModel_typeInfo[];

unsigned short ISimsWallObjectModel::GetTypeVersion() const {
    return ISimsWallObjectModel_typeInfo[10];
}
