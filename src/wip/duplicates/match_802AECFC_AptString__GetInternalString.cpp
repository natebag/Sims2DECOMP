// 0x802AECFC (8 bytes)
class AptString {
public:
    int GetInternalString();
};

int AptString::GetInternalString() {
    return (int)((char*)this + 0xC);
}
