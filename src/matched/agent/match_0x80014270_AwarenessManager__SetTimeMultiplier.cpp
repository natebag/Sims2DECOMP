/* AwarenessManager::SetTimeMultiplier(float) at 0x80014270 (8B) */

struct AwarenessManager {
    char pad[0x2C];
    float m_timeMultiplier;

    void SetTimeMultiplier(float val);
};

void AwarenessManager::SetTimeMultiplier(float val) {
    m_timeMultiplier = val;
}
