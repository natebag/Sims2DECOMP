// 0x80141A54 (8 bytes)
class cSimulatorImpl {
public:
    void SetGbaNumMinigames(int p);
};

void cSimulatorImpl::SetGbaNumMinigames(int p) {
    *(short*)((char*)this + 0x6E) = (short)p;
}
