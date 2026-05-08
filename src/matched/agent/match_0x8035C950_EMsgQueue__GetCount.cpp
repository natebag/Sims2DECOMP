// 0x8035C950 EMsgQueue::GetCount(void) (36B)

struct EMsgQueue {
    char pad[48];
    int m_head;   // +48
    int m_tail;   // +52
    int m_size;   // +56
    int GetCount();
};

int EMsgQueue::GetCount() {
    int tail = m_tail;
    int head = m_head;
    if (head < tail) head += m_size;
    return head - tail;
}
