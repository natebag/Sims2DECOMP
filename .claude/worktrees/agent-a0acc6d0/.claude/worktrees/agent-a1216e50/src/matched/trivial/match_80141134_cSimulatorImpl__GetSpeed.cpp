// 0x80141134 (8 bytes)
class cSimulatorImpl {
public:
    short GetSpeed();
};

short cSimulatorImpl::GetSpeed() {
    return *(short*)((char*)this + 0x34);
}
