// 0x80087AD4 (8 bytes)
class WrapperPaneBase {
public:
    char pad[48];
    float m_alpha;

    void SetAlpha(float alpha);
};

void WrapperPaneBase::SetAlpha(float alpha) {
    m_alpha = alpha;
}
