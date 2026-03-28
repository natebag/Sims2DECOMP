/* AwarenessManager::GetAwarenessAction(void) at 0x80014248 (8B) */

struct AwarenessManager {
    char pad[0x18];
    int m_awarenessAction;

    int GetAwarenessAction(void);
};

int AwarenessManager::GetAwarenessAction(void) {
    return m_awarenessAction;
}
