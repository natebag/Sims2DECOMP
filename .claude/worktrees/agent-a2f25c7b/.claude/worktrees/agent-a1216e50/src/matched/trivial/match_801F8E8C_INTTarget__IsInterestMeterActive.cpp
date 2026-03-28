// 0x801F8E8C (8 bytes)
class INTTarget {
public:
    int IsInterestMeterActive();
};

int INTTarget::IsInterestMeterActive() {
    return *(int*)((char*)this + 0x88);
}
