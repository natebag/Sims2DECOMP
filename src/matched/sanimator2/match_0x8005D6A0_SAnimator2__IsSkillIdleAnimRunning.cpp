/* 0x8005D6A0 (52 bytes) - SAnimator2::IsSkillIdleAnimRunning(void) */
class ESim;
struct SAnimator2 {
    char pad[8];
    ESim* m_sim;
    int IsSkillIdleAnimRunning();
};

int SAnimator2::IsSkillIdleAnimRunning() {
    unsigned char* obj = (unsigned char*)m_sim;
    unsigned char* helper = obj + 820;
    int idx = *(int*)(helper + 8);
    int flags;
    if (idx != -1) {
        unsigned char* base = *(unsigned char**)(helper + 68);
        flags = *(int*)(base + idx * 176 + 48);
    } else {
        flags = 0;
    }
    return (flags >> 5) & 1;
}
