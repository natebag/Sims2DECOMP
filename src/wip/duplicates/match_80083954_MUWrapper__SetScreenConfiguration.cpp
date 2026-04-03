// 0x80083954 (8 bytes)
class MUWrapper {
public:
    void SetScreenConfiguration(int p);
};

void MUWrapper::SetScreenConfiguration(int p) {
    *(int*)((char*)this + 0xAC) = p;
}
