/* EAHeap::FindHeapForAddress(void*) - 0x802D0F24 (124 bytes) */

struct EAHeap {
    char _pad[0x52c];
    EAHeap *m_field52c;
    EAHeap *m_field530;

    int Contains(void *addr);
    void *FindHeapForAddress(void *addr);
};

void *EAHeap::FindHeapForAddress(void *addr) {
    if (Contains(addr))
        return this;

    if (m_field52c != 0) {
        void *r = m_field52c->FindHeapForAddress(addr);
        if (r != 0)
            return r;
    }

    if (m_field530 != 0) {
        void *r = m_field530->FindHeapForAddress(addr);
        if (r != 0)
            return r;
    }

    return 0;
}
