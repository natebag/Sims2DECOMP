// 0x8032076C (60B) ERShader::GetCurrentShader(void)
// IsMultiShader-guarded accessor: returns m_currentShader at +0x18 if valid, else 0.

class ERShader {
public:
    char pad[0x18];
    void* m_currentShader;       // offset 0x18

    bool IsMultiShader() const;
    void* GetCurrentShader();
};

void* ERShader::GetCurrentShader() {
    if (IsMultiShader()) {
        return m_currentShader;
    }
    return 0;
}
