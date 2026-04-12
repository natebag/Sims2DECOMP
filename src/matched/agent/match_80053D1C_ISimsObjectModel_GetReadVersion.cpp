// 0x80053D1C (12 bytes)
// TU: iobject
class ISimsObjectModel {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short ISimsObjectModel_typeInfo[];

unsigned short ISimsObjectModel::GetReadVersion() const {
    return ISimsObjectModel_typeInfo[11];
}
