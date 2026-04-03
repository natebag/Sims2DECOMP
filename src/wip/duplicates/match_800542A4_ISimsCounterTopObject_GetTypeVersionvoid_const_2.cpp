// 0x800542A4 (12 bytes)
class ISimsCounterTopObject {
public:
    short GetTypeVersion() const;
};

extern char gISimsCounterTopObjectData[];

short ISimsCounterTopObject::GetTypeVersion() const {
    return *(short*)(gISimsCounterTopObjectData + 0);
}
