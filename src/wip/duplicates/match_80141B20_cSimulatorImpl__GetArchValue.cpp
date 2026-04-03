// 0x80141B20 (8 bytes)
class cSimulatorImpl {
public:
    int GetArchValue();
};

int cSimulatorImpl::GetArchValue() {
    return *(int*)((char*)this + 0x8C);
}
