// 0x801B4458 (8 bytes)
class FCMTarget {
public:
    int IsFireCodeMeterActive();
};

int FCMTarget::IsFireCodeMeterActive() {
    return *(int*)((char*)this + 0x88);
}
