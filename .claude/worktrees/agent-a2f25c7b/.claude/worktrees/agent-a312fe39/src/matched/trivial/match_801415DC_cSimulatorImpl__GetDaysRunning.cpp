// 0x801415DC (8 bytes)
class cSimulatorImpl {
public:
    short GetDaysRunning();
};

short cSimulatorImpl::GetDaysRunning() {
    return *(short*)((char*)this + 0x4C);
}
