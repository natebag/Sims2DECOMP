/* EAHeap::Clear(void) - 0x802D0E88 (76 bytes) */

struct EAHeap {
    char _pad[0x534];
    int m_field534;
    void Reset(int region, int flag);
    void Clear(void);
};

void EAHeap::Clear(void) {
    m_field534 = 0;
    Reset(2, 0);
    Reset(10, 0);
}
