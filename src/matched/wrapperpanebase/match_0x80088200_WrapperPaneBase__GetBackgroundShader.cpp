struct ERShader;

struct WrapperPaneBase {
    char pad[0x18];
    ERShader *m_bgShader;

    ERShader *GetBackgroundShader(void);
};

ERShader *WrapperPaneBase::GetBackgroundShader(void) {
    return m_bgShader;
}
