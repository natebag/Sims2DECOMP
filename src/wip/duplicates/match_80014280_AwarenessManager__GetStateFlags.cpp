// 0x80014280 (8 bytes) — lwz r3, 0x0(r3); blr

class AwarenessManager {
public:
    int m_stateFlags;  // 0x000

    int GetStateFlags();
};

int AwarenessManager::GetStateFlags() {
    return m_stateFlags;
}
