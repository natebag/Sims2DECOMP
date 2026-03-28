// 0x80141A44 (8 bytes)
class cSimulatorImpl {
public:
    void SetGbaStatus(int p);
};

void cSimulatorImpl::SetGbaStatus(int p) {
    *(short*)((char*)this + 0x6A) = (short)p;
}
