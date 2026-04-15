// 0x8015AB2C (100B) ObjectDataBehaviorTree::GetNumParams(void) const

struct ObjectDataBehaviorTree {
    char pad[84];
    unsigned char* m_data;
    short GetStructVersion() const;
    int GetNumParams() const;
};

int ObjectDataBehaviorTree::GetNumParams() const {
    if (GetStructVersion() >= -32766) return m_data[5];
    if (GetStructVersion() == -32767) {
        unsigned int n = m_data[5];
        if (n <= 4) return n;
    }
    return 4;
}
