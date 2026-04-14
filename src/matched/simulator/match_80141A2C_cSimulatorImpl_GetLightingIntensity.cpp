// 0x80141A2C (12 bytes)
// cSimulatorImpl::GetLightingIntensity(void)
// lhz r3, 104(r3); rlwinm r3, r3, 0, 23, 31; blr
class cSimulatorImpl {
public:
    char m_pad[104];
    unsigned short m_lightingFlags;
    int GetLightingIntensity();
};

int cSimulatorImpl::GetLightingIntensity() {
    return m_lightingFlags & 0x1FF;
}
