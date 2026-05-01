// 0x803207BC (60B) ERShader::GetStateCount(void)
// IsMultiShader-guarded accessor: returns m_stateCount byte at +0x44, else 0.

class ERShader {
public:
    char pad[0x44];
    unsigned char m_stateCount;   // offset 0x44

    bool IsMultiShader() const;
    int  GetStateCount();
};

int ERShader::GetStateCount() {
    if (IsMultiShader()) {
        return m_stateCount;
    }
    return 0;
}
