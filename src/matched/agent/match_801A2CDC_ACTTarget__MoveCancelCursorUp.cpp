struct CancelNode {
    int m_type;
    char _pad[0x40];
    CancelNode *m_prev;
    CancelNode *m_next;
};

class ACTTarget {
public:
    char _pad[0x648];
    CancelNode *m_curNode;
    CancelNode *m_prevNode;

    void UpdateCancelModeWidgets();
    void MoveCancelCursorUp();
};

void ACTTarget::MoveCancelCursorUp() {
    CancelNode *cur = m_curNode;
    if (cur != 0) {
        CancelNode *prev = cur->m_prev;
        if (prev != 0) {
            if (prev->m_type <= 8) {
                m_prevNode = cur;
                m_curNode = cur->m_prev;
                UpdateCancelModeWidgets();
            }
        }
    }
}
