// 0x8034A51C (28B) ENgcRenderer::GetRenderMode(void)

struct ENgcRenderer {
    char pad[0x34C];
    int m_renderMode;

    int GetRenderMode(void);
};

int ENgcRenderer::GetRenderMode(void) {
    int mode = m_renderMode;
    if (mode == 0) {
        return 0;
    }
    mode += 0x364;
    return mode;
}
