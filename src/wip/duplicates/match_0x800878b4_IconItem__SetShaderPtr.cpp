struct ERShader;

struct IconItem {
    char pad[0x30];
    ERShader *m_shader;

    void SetShader(ERShader *shader);
};

void IconItem::SetShader(ERShader *shader) {
    m_shader = shader;
}
