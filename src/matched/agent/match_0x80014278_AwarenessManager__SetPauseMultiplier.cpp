/* AwarenessManager::SetPauseMultiplier(float) at 0x80014278 (8B) */

struct AwarenessManager {
    char pad[0x30];
    float m_pauseMultiplier;

    void SetPauseMultiplier(float val);
};

void AwarenessManager::SetPauseMultiplier(float val) {
    m_pauseMultiplier = val;
}
