// 0x80324850 EDatasetManager::GetLoadingEnabled(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-26632(13)"

struct EDatasetManager {
    void GetLoadingEnabled();
};

void EDatasetManager::GetLoadingEnabled() {
}
