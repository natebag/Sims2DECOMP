// 0x802D8538 EThread::GetThreadObject(int) (48B)
// Static search: scan _threadList linked list for node with m_threadId==id.
// b-forward skips advance on first iteration (while-loop pattern).
// Match path: mr r11,r9; mr r3,r11. Null-exit: beq direct to blr (r3 undefined).
// _threadList SDA global at r13-22764 = 0x80500034.

struct EThread {
    char pad[0x318];
    int m_threadId;      // offset 0x318 = 792
    char pad2[0x18];
    EThread* m_next;     // offset 0x334 = 820

    static EThread* GetThreadObject(int id);
};

extern EThread* _threadList;

EThread* EThread::GetThreadObject(int id) {
    EThread* node = _threadList;
    EThread* result = 0;
    while (node) {
        if (node->m_threadId == id) {
            result = node;
            break;
        }
        node = node->m_next;
    }
    return result;
}
