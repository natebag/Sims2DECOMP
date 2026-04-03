// 0x80141B18 (8 bytes)
class cSimulatorImpl {
public:
    void SetLotValue(int p);
};

void cSimulatorImpl::SetLotValue(int p) {
    *(int*)((char*)this + 0x84) = p;
}
