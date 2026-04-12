// 0x800542A4 (12 bytes)
// TU: iobject
class ISimsCounterTopObject {
public:
    unsigned short GetTypeVersion() const;
};

extern unsigned short ISimsCounterTopObject_typeInfo[];

unsigned short ISimsCounterTopObject::GetTypeVersion() const {
    return ISimsCounterTopObject_typeInfo[10];
}
