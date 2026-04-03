// 0x80141A84 (8 bytes)
class cSimulatorImpl {
public:
    float GetSpeedMultiplier();
};

float cSimulatorImpl::GetSpeedMultiplier() {
    return *(float*)((char*)this + 0xA8);
}
