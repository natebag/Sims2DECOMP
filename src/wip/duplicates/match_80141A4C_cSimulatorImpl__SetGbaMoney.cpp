// 0x80141A4C (8 bytes)
class cSimulatorImpl {
public:
    void SetGbaMoney(int p);
};

void cSimulatorImpl::SetGbaMoney(int p) {
    *(short*)((char*)this + 0x6C) = (short)p;
}
