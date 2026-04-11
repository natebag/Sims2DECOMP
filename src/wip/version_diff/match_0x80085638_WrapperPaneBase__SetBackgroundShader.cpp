/* WrapperPaneBase::SetBackgroundShader(unsigned int) at 0x80085638 (64B) */

extern void *FindShader(void *, unsigned int, int, int);
extern char g_shaderPool[];

struct WrapperPaneBase {
    char pad[0x18];
    void *m_bgShader;

    void SetBackgroundShader(unsigned int shaderId);
};

void WrapperPaneBase::SetBackgroundShader(unsigned int shaderId) {
    m_bgShader = FindShader(g_shaderPool, shaderId, 0, 0);
}
