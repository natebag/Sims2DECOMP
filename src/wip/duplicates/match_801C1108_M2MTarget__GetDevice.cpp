// 0x801C1108 (8 bytes)
class M2MTarget {
public:
    int GetDevice();
};

int M2MTarget::GetDevice() {
    return *(int*)((char*)this + 0x10C);
}
