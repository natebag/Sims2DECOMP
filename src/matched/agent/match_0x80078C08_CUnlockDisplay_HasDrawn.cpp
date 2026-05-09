// 0x80078C08 (60B) CUnlockDisplay::HasDrawn(void)
// Walk linked list at this+1124; result = AND of (node->m_field124 != 0).
// Returns 1 if all nodes have non-zero m_field124, else 0.

class UnlockNode {
public:
    UnlockNode* m_next;  // +0
    char _pad[120];
    int m_field124;      // +124
};

class CUnlockDisplay {
public:
    char _pad[1124];
    UnlockNode* m_head;  // +1124
    int HasDrawn();
};

int CUnlockDisplay::HasDrawn()
{
    UnlockNode* cur = m_head;
    int result = 1;
    while (cur != 0) {
        result = result && (cur->m_field124 != 0);
        cur = cur->m_next;
    }
    return result;
}
