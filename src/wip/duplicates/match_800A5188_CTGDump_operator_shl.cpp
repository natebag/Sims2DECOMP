// 0x800A5188 (4 bytes)
// CTGDump::operator<<(char *)
class CTGDump {
public:
    CTGDump& operator<<(char* s);
};

CTGDump& CTGDump::operator<<(char* s) {
    return *this;
}
