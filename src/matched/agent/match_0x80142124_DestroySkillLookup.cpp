extern void* gSkillLookup;
extern "C" void destroyLookup(void*, int);
void DestroySkillLookup() {
    if (gSkillLookup) {
        destroyLookup(gSkillLookup, 3);
    }
    gSkillLookup = 0;
}
