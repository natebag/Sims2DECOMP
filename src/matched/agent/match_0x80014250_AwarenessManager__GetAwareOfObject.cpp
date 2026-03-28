/* AwarenessManager::GetAwareOfObject(void) at 0x80014250 (8B) */

struct AwarenessManager {
    char pad[0x1C];
    int m_awareOfObject;

    int GetAwareOfObject(void);
};

int AwarenessManager::GetAwareOfObject(void) {
    return m_awareOfObject;
}
