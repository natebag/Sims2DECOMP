// 0x803208B4 ERShader::DetachClone(void) (40 B)

class ERShader {
    char pad[0x4];
    int m_cloneCount;
public:
    void DetachClone(void);
};

void ERShader::DetachClone(void) {
    int flag = 1;
    if (m_cloneCount == 0) flag = 0;
    if (flag == 0) return;
    m_cloneCount = 0;
}
