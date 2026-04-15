// 0x800C1034 IFFResFile2::SetOptimizeTarget (12B)
struct IFFResFile2 {
    char pad[328];
    int m_optimizeTarget;
    void SetOptimizeTarget();
};
void IFFResFile2::SetOptimizeTarget() { m_optimizeTarget = 1; }
