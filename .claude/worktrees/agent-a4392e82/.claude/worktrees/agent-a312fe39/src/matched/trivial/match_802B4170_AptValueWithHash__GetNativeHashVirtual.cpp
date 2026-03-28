// 0x802B4170 (8 bytes)
class AptValueWithHash {
public:
    int GetNativeHashVirtual();
};

int AptValueWithHash::GetNativeHashVirtual() {
    return (int)((char*)this + 0xC);
}
