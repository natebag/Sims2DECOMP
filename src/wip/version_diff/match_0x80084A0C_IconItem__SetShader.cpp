/* IconItem::SetShader(unsigned int) at 0x80084A0C (64B) */

extern void *FindShader(void *, unsigned int, int, int);
extern char g_shaderPool[];

struct IconItem {
    char pad[0x30];
    void *m_shader;

    void SetShader(unsigned int shaderId);
};

void IconItem::SetShader(unsigned int shaderId) {
    m_shader = FindShader(g_shaderPool, shaderId, 0, 0);
}
