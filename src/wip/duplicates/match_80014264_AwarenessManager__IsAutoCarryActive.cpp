// 0x80014264 (12 bytes) — lwz r3, 0(r3); rlwinm r3, r3, 23, 31, 31; blr
// Extracts bit 9 from stateFlags at offset 0

class AwarenessManager {
public:
    unsigned int m_stateFlags;  // 0x000

    bool IsAutoCarryActive();
};

bool AwarenessManager::IsAutoCarryActive() {
    return (m_stateFlags >> 9) & 1;
}
