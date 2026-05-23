// 0x80320654 (44B) ERShader::GetShader(void)
// Leaf accessor: returns m_currentShader if set, else fallback->m_currentShader, else 0.

class ERShader {
public:
    char pad[0x14];
    void* m_currentShader;     // 0x14
    ERShader* m_fallback;      // 0x18

    void* GetShader();
};

void* ERShader::GetShader() {
    if (m_currentShader) return m_currentShader;
    if (m_fallback) return m_fallback->m_currentShader;
    return 0;
}
