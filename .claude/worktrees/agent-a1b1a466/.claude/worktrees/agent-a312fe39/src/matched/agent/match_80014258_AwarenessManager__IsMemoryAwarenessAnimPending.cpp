// 0x80014258 (12 bytes) — lwz r3, 0(r3); rlwinm r3, r3, 28, 31, 31; blr
// Extracts bit 4 from stateFlags at offset 0

class AwarenessManager {
public:
    unsigned int m_stateFlags;  // 0x000

    bool IsMemoryAwarenessAnimPending();
};

bool AwarenessManager::IsMemoryAwarenessAnimPending() {
    return (m_stateFlags >> 4) & 1;
}
