struct CancelNode {
    char _pad[0x48];
    CancelNode *m_next;
};

class ACTTarget {
public:
    char _pad[0x648];
    CancelNode *m_curNode;
    CancelNode *m_prevNode;

    void UpdateCancelModeWidgets();
    void MoveCancelCursorDown();
};

void ACTTarget::MoveCancelCursorDown() {
    CancelNode *cur = m_curNode;
    if (cur != 0) {
        if (cur->m_next != 0) {
            m_prevNode = cur;
            m_curNode = cur->m_next;
            UpdateCancelModeWidgets();
        }
    }
}
