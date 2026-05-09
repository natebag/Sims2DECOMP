struct AnimEntry {
    char _pad[0x30];
    int m_flags;
};

struct SAnimator2 {
    char _pad[8];
    void* m_pSim;
};

int SAnimator2_IsSkillIdleAnimRunning(SAnimator2* self) {
    void* sim = self->m_pSim;
    int idx = *(int*)((char*)sim + 0x33C);
    if (idx == -1) {
        return 0;
    }
    void* array = *(void**)((char*)sim + 0x378);
    AnimEntry* entry = (AnimEntry*)((char*)array + idx * 176);
    return (entry->m_flags >> 5) & 1;
}
