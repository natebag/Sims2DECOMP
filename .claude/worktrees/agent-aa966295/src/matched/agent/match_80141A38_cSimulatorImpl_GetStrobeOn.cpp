// 0x80141A38 (12 bytes)
// cSimulatorImpl::GetStrobeOn(void)
// lhz r3, 104(r3); rlwinm r3, r3, 23, 31, 31; blr
class cSimulatorImpl {
public:
    char m_pad[104];
    unsigned short m_lightingFlags;
    int GetStrobeOn();
};

int cSimulatorImpl::GetStrobeOn() {
    return (m_lightingFlags >> 9) & 1;
}
