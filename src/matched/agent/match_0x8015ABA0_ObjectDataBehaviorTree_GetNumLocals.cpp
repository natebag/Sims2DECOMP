// 0x8015ABA0 (112B) ObjectDataBehaviorTree::GetNumLocals(void) const

struct ObjectDataBehaviorTree {
    char pad[84];
    unsigned char* m_data;
    short GetStructVersion() const;
    int GetNumLocals() const;
};

int ObjectDataBehaviorTree::GetNumLocals() const {
    if (GetStructVersion() >= -32766) return m_data[6];
    if (GetStructVersion() != -32767) return 0;
    unsigned int n = m_data[6];
    if (n <= 4) return n;
    return 4;
}
