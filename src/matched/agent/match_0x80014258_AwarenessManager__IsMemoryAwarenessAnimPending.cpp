/* AwarenessManager::IsMemoryAwarenessAnimPending(void) at 0x80014258 (12B) */

struct AwarenessManager {
    unsigned int m_stateFlags;

    int IsMemoryAwarenessAnimPending(void);
};

int AwarenessManager::IsMemoryAwarenessAnimPending(void) {
    return (m_stateFlags >> 4) & 1;
}
