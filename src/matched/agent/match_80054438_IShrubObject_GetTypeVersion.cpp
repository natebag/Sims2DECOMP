// 0x80054438 (12 bytes)
// TU: iobject
class IShrubObject {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short IShrubObject_typeInfo[];

unsigned short IShrubObject::GetTypeVersion() const {
    return IShrubObject_typeInfo[10];
}
