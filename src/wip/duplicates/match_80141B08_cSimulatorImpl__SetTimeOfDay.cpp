// 0x80141B08 (8 bytes)
class cSimulatorImpl {
public:
    void SetTimeOfDay(int p);
};

void cSimulatorImpl::SetTimeOfDay(int p) {
    *(short*)((char*)this + 0x1C) = (short)p;
}
