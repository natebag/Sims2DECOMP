extern void SomeFunction(const char*, int);
extern char g_string[];

struct REffectsAttachment {
    char _pad[0x14];
    char* m_start;
    char* m_end;
};

void SAnimator2_PreloadBoneParticleEvent(REffectsAttachment* attach) {
    int count = (attach->m_end - attach->m_start) >> 3;
    int offset = 0;
    while (count > 0) {
        int id = *(int*)(attach->m_start + offset + 4);
        if (id != 0) {
            SomeFunction(g_string, id);
        }
        offset += 8;
        count--;
    }
}
