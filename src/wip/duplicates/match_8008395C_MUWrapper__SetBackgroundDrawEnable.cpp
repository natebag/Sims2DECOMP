// 0x8008395C (8 bytes)
class MUWrapper {
public:
    void SetBackgroundDrawEnable(int p);
};

void MUWrapper::SetBackgroundDrawEnable(int p) {
    *(int*)((char*)this + 0xC8) = p;
}
