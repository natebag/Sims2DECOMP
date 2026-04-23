// 0x802854F8 (52B) AptActionQueueC::GetDequeSize(void) const

struct DequeElement {
    char data[20];
};

struct AptActionQueueC {
    DequeElement* m_begin;
    DequeElement* m_tail;
    DequeElement* m_end;
    char pad[4];
    int m_capacity;

    int GetDequeSize() const;
};

int AptActionQueueC::GetDequeSize() const {
    int size = m_end - m_tail;
    if (size >= 0) {
        return size;
    }
    return size + m_capacity;
}
