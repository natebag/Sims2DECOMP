struct WrapperPaneBase {
    char pad[0x2C];
    float m_bgAlpha;

    void SetBackgroundAlpha(float alpha);
};

void WrapperPaneBase::SetBackgroundAlpha(float alpha) {
    m_bgAlpha = alpha;
}
