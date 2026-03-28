struct LevelLighting;
struct LevelLightingEntry;

void InterpolateLevelLighting(LevelLighting *, float, LevelLightingEntry &);

struct ERLevel {
    char pad0[0x2E454];
    LevelLighting *m_levelLighting;

    void OutsideLightsInit(float time, LevelLightingEntry &entry);
};

void ERLevel::OutsideLightsInit(float time, LevelLightingEntry &entry) {
    InterpolateLevelLighting(m_levelLighting, time, entry);
}
