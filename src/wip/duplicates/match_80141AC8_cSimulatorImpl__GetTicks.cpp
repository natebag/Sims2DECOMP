// 0x80141AC8 (8 bytes)
class cSimulatorImpl {
public:
    int GetTicks();
};

int cSimulatorImpl::GetTicks() {
    return *(int*)((char*)this + 0x7C);
}
