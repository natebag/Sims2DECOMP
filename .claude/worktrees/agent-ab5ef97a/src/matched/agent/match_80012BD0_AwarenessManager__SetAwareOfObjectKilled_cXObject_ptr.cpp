struct cXObject;

struct AwarenessManager {
    int m_flags;
    char pad[24];
    cXObject* m_killedObject;
    int SetAwareOfObjectKilled(cXObject*);
};

int AwarenessManager::SetAwareOfObjectKilled(cXObject* obj)
{
    if (m_killedObject != 0 && m_killedObject == obj) {
        m_flags |= 0x800;
        return 1;
    }
    return 0;
}

