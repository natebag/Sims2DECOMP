// 0x800542BC (12 bytes)
// TU: iobject
class ISimsCounterTopObject {
public:
    unsigned short GetReadVersion() const;
};

extern unsigned short ISimsCounterTopObject_typeInfo[];

unsigned short ISimsCounterTopObject::GetReadVersion() const {
    return ISimsCounterTopObject_typeInfo[11];
}
