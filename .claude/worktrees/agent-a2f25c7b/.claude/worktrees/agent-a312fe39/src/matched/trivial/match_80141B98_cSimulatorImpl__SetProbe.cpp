// 0x80141B98 (8 bytes)
class cSimulatorImpl {
public:
    void SetProbe(int p);
};

void cSimulatorImpl::SetProbe(int p) {
    *(int*)((char*)this + 0x94) = p;
}
