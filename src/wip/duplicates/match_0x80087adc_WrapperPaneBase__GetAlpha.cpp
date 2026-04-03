struct WrapperPaneBase {
    char pad[0x30];
    float m_alpha;

    float GetAlpha(void);
};

float WrapperPaneBase::GetAlpha(void) {
    return m_alpha;
}
