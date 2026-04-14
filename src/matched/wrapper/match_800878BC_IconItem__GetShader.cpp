// 0x800878BC (8 bytes)
typedef void ERShader;

class IconItem {
public:
    char pad[48];
    ERShader *m_shader;

    ERShader *GetShader(void);
};

ERShader *IconItem::GetShader(void) {
    return m_shader;
}
