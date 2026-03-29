// 0x80054450 (12 bytes)
class IShrubObject {
public:
    short GetReadVersion() const;
};

extern char gIShrubObjectData[];

short IShrubObject::GetReadVersion() const {
    return *(short*)(gIShrubObjectData + 0);
}
