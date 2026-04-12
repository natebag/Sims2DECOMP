// 0x80053D04 (12 bytes)
// TU: iobject
class ISimsObjectModel {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short ISimsObjectModel_typeInfo[];

unsigned short ISimsObjectModel::GetTypeVersion() const {
    return ISimsObjectModel_typeInfo[10];
}
