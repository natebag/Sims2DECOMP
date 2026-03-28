class EGraphics {
public:
    char m_pad[800];
    int m_enableFrameEffects;
    int IsEnableFrameEffects();
};
int EGraphics::IsEnableFrameEffects() { return m_enableFrameEffects; }
