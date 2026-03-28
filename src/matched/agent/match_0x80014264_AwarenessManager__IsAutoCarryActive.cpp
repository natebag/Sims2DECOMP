/* AwarenessManager::IsAutoCarryActive(void) at 0x80014264 (12B) */

struct AwarenessManager {
    unsigned int m_stateFlags;

    int IsAutoCarryActive(void);
};

int AwarenessManager::IsAutoCarryActive(void) {
    return (m_stateFlags >> 9) & 1;
}
