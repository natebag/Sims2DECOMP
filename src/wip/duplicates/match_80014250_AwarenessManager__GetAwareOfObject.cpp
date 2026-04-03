// 0x80014250 (8 bytes) — lwz r3, 0x1C(r3); blr

class AwarenessManager {
public:
    char _pad[0x1C];
    void* m_awareOfObject;

    void* GetAwareOfObject();
};

void* AwarenessManager::GetAwareOfObject() {
    return m_awareOfObject;
}
