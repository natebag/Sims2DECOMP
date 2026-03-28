// 0x80141AB8 (8 bytes)
class cSimulatorImpl {
public:
    short GetMode();
};

short cSimulatorImpl::GetMode() {
    return *(short*)((char*)this + 0x3A);
}
