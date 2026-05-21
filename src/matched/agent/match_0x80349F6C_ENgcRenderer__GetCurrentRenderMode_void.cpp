// 0x80349F6C ENgcRenderer::GetCurrentRenderMode(void) (104B)
// Returns a 60-byte ERenderMode by value (hidden out-param r3, this=r4)
// Inline copy ctor avoids GCC 2.95 bug with 60-byte struct copy construction

struct ERenderMode {
    int data[15];
    ERenderMode() {}
    inline ERenderMode(const ERenderMode& o) {
        __builtin_memcpy(this, &o, sizeof(ERenderMode));
    }
};

struct ENgcRenderer {
    char _pad[868];
    ERenderMode m_currentRenderMode;
    ERenderMode GetCurrentRenderMode() const;
};

ERenderMode ENgcRenderer::GetCurrentRenderMode() const {
    return m_currentRenderMode;
}
