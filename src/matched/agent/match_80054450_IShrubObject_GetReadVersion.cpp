// 0x80054450 (12 bytes)
// TU: iobject
class IShrubObject {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short IShrubObject_typeInfo[];

unsigned short IShrubObject::GetReadVersion() const {
    return IShrubObject_typeInfo[11];
}
