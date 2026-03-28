// 0x80035330 (8 bytes) — lwz r3, 0x628(r3); blr

class ESim {
public:
    char _pad[0x628];
    void* m_simHead;

    void* GetSimHead();
};

void* ESim::GetSimHead() {
    return m_simHead;
}
