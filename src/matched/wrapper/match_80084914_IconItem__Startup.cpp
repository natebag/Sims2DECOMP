// 0x80084914 (12 bytes)
typedef void ERShader;

class IconItem {
public:
    char pad[48];
    ERShader *m_shader;

    void Startup(void);
};

void IconItem::Startup(void) {
    m_shader = 0;
}
