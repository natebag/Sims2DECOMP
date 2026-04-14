// 0x80087ADC (8 bytes)
class WrapperPaneBase {
public:
    char pad[48];
    float m_alpha;

    float GetAlpha(void);
};

float WrapperPaneBase::GetAlpha(void) {
    return m_alpha;
}
