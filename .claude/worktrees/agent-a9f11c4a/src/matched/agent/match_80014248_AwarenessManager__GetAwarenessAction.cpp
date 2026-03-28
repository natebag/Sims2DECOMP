// 0x80014248 (8 bytes) — lwz r3, 0x18(r3); blr

class AwarenessManager {
public:
    char _pad[0x18];
    int m_awarenessAction;

    int GetAwarenessAction();
};

int AwarenessManager::GetAwarenessAction() {
    return m_awarenessAction;
}
