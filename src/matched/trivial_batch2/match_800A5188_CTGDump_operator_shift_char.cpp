// 0x800A5188 (4 bytes)
class CTGDump {
public:
    CTGDump& operator<<(char*);
};

CTGDump& CTGDump::operator<<(char* msg) {
    return *this;
}
