/* AwarenessManager::GetStateFlags(void) at 0x80014280 (8B) */

struct AwarenessManager {
    int m_stateFlags;

    int GetStateFlags(void);
};

int AwarenessManager::GetStateFlags(void) {
    return m_stateFlags;
}
