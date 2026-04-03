// 0x80141AC0 (8 bytes)
class cSimulatorImpl {
public:
    void SetMode(int p);
};

void cSimulatorImpl::SetMode(int p) {
    *(short*)((char*)this + 0x3A) = (short)p;
}
