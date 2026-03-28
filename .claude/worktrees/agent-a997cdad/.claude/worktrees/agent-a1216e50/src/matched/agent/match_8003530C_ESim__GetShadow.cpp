// 0x8003530C (8 bytes) — lwz r3, 0x3E0(r3); blr

class ESim {
public:
    char _pad[0x3E0];
    void* m_shadow;

    void* GetShadow();
};

void* ESim::GetShadow() {
    return m_shadow;
}
