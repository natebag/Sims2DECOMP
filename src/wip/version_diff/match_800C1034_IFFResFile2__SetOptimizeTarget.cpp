/* IFFResFile2::SetOptimizeTarget(void) - 0x800C1034 (12 bytes) */

struct IFFResFile2 {
    char m_pad[0x148];
    int m_optimizeTarget;

    void SetOptimizeTarget(void);
};

void IFFResFile2::SetOptimizeTarget(void) {
    m_optimizeTarget = 1;
}
