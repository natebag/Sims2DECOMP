// 0x80014270 (8 bytes) — stfs f1, 0x2C(r3); blr

class AwarenessManager {
public:
    char _pad[0x2C];
    float m_timeMultiplier;

    void SetTimeMultiplier(float val);
};

void AwarenessManager::SetTimeMultiplier(float val) {
    m_timeMultiplier = val;
}
