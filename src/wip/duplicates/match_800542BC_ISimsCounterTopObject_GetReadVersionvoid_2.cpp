// 0x800542BC (12 bytes)
class ISimsCounterTopObject {
public:
    short GetReadVersion() const;
};

extern char gISimsCounterTopObjectData[];

short ISimsCounterTopObject::GetReadVersion() const {
    return *(short*)(gISimsCounterTopObjectData + 0);
}
