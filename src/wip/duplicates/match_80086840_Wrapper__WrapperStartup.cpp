// 0x80086840 (8 bytes)
class Wrapper {
public:
    void WrapperStartup(int p);
};

void Wrapper::WrapperStartup(int p) {
    *(int*)((char*)this + 0x88) = p;
}
