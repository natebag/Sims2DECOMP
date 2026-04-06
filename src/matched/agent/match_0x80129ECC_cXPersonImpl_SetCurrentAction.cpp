// 0x80129ECC cXPersonImpl::SetCurrentAction (68b)

struct Interaction;

struct ActionQueue {
    void Insert(Interaction& action, unsigned int index);
};

struct cXPersonImpl {
    char pad[0x130];                // pad to ActionQueue at 0x130
    ActionQueue m_actionQueue;      // at offset 0x130
    char pad2[0x400];               // pad to 0x530 (4 bytes before 0x534)
    int m_currentActionIndex;       // at offset 0x534 (1332)
    
    void SetCurrentAction(Interaction& action);
    void UpdateCurrentAction();
};

void cXPersonImpl::SetCurrentAction(Interaction& action) {
    m_currentActionIndex = 1;
    m_actionQueue.Insert(action, 0);
    UpdateCurrentAction();
}
