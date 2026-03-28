// 0x801A7674 (8 bytes)
class CSMTarget {
public:
    int IsCSIMActive();
};

int CSMTarget::IsCSIMActive() {
    return *(int*)((char*)this + 0x88);
}
