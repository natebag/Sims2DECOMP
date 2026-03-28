// 0x800878B4 (8 bytes)
typedef void ERShader;

class IconItem {
public:
    char pad[48];
    ERShader *m_shader;

    void SetShader(ERShader *shader);
};

void IconItem::SetShader(ERShader *shader) {
    m_shader = shader;
}
