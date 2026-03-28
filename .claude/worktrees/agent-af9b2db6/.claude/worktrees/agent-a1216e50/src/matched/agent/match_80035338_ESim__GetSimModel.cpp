// 0x80035338 (8 bytes) — lwz r3, 0x63C(r3); blr

class ESim {
public:
    char _pad[0x63C];
    void* m_simModel;

    void* GetSimModel();
};

void* ESim::GetSimModel() {
    return m_simModel;
}
