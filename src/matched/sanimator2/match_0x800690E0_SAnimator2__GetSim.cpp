/* 0x800690E0 (8 bytes) - SAnimator2::GetSim(void) */
class ESim;
struct SAnimator2 {
    char pad[8];
    ESim* m_sim;
    ESim* GetSim();
};
ESim* SAnimator2::GetSim() { return m_sim; }
