struct ERShader;

struct IconItem {
    char pad[0x30];
    ERShader *m_shader;

    ERShader *GetShader(void);
};

ERShader *IconItem::GetShader(void) {
    return m_shader;
}
