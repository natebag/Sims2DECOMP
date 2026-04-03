// 0x800BEA00 (8 bytes)
class IFFResFile2 {
public:
    int Writable();
};

int IFFResFile2::Writable() {
    return *(int*)((char*)this + 0x11C);
}
