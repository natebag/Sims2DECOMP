/* ObjectModuleImpl::ClearKillQueue(void) - 12 bytes */

class ObjectModuleImpl {
public:
    char pad[0x2044];
    int m_killQueueHead;
    int m_killQueueTail;

    void ClearKillQueue(void);
};

void ObjectModuleImpl::ClearKillQueue(void) {
    m_killQueueTail = m_killQueueHead;
}
