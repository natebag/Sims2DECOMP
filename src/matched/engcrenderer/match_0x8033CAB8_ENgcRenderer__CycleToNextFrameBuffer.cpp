// 0x8033CAB8 ENgcRenderer::CycleToNextFrameBuffer(void) (100B)
// Pattern: VISetNextFrameBuffer(currentFb) + idx = (idx+1) % 2 + currentFb = fbs[idx] +
// VIFlush + VIWaitForRetrace. The mod-2 emits the signed shift trick (srwi 31 + add + clrrwi).

extern "C" void VISetNextFrameBuffer(void* fb);
extern "C" void VIFlush();
extern "C" void VIWaitForRetrace();

class ENgcRenderer {
public:
    char pad_0[832];
    int m_idx;                  // 832 (0x340)
    void* m_fbs[2];             // 836 (0x344) + 840 (0x348)
    void* m_currentFb;          // 844 (0x34C)

    void CycleToNextFrameBuffer();
};

void ENgcRenderer::CycleToNextFrameBuffer() {
    VISetNextFrameBuffer(m_currentFb);
    int idx = (m_idx + 1) % 2;
    m_idx = idx;
    m_currentFb = m_fbs[idx];
    VIFlush();
    VIWaitForRetrace();
}
