// 0x80141B10 (8 bytes)
class cSimulatorImpl {
public:
    int GetLotValue();
};

int cSimulatorImpl::GetLotValue() {
    return *(int*)((char*)this + 0x84);
}
