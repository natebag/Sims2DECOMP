// 0x80141B90 (8 bytes)
class cSimulatorImpl {
public:
    int GetProbe();
};

int cSimulatorImpl::GetProbe() {
    return *(int*)((char*)this + 0x94);
}
