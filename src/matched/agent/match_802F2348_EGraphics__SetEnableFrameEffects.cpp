class EGraphics {
public:
    char m_pad[800];
    int m_enableFrameEffects;
    void SetEnableFrameEffects(bool);
};
void EGraphics::SetEnableFrameEffects(bool enable) { m_enableFrameEffects = enable; }
