// AwarenessManager::SetPlayerControl(bool) — 40B @ 0x800122B0

class AwarenessManager {
public:
    void SetPlayerControl(bool enable);
private:
    int stateFlags;
};

void AwarenessManager::SetPlayerControl(bool enable) {
    if (enable == 1) {
        stateFlags |= 1;
    } else {
        stateFlags &= ~1;
    }
}
