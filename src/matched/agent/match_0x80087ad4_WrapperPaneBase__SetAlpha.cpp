struct WrapperPaneBase {
    char pad[0x30];
    float m_alpha;

    void SetAlpha(float alpha);
};

void WrapperPaneBase::SetAlpha(float alpha) {
    m_alpha = alpha;
}
