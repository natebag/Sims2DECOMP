// FLAGS: -fno-schedule-insns
// 0x80324850 EDatasetManager::GetLoadingEnabled(void) (8B)
// lwz r3,gLoadingEnabled(r13); blr  -- returns SDA global
extern int gLoadingEnabled;

struct EDatasetManager {
    int GetLoadingEnabled();
};

int EDatasetManager::GetLoadingEnabled() { return gLoadingEnabled; }
