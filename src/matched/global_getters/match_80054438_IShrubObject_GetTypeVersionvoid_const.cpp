// 0x80054438 (12 bytes)
class IShrubObject {
public:
    short GetTypeVersion() const;
};

extern char gIShrubObjectData[];

short IShrubObject::GetTypeVersion() const {
    return *(short*)(gIShrubObjectData + 0);
}
