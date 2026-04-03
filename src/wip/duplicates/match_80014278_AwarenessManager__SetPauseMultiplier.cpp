// 0x80014278 (8 bytes) — stfs f1, 0x30(r3); blr

class AwarenessManager {
public:
    char _pad[0x30];
    float m_pauseMultiplier;

    void SetPauseMultiplier(float val);
};

void AwarenessManager::SetPauseMultiplier(float val) {
    m_pauseMultiplier = val;
}
