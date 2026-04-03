// 0x801C9C84 (8 bytes)
class MODTarget {
public:
    int IsMoodActive();
};

int MODTarget::IsMoodActive() {
    return *(int*)((char*)this + 0x88);
}
