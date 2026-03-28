class EGraphics {
public:
    char m_pad[796];
    int m_firstPassRenderOnly;
    void EnableNormalRender();
};
void EGraphics::EnableNormalRender() { m_firstPassRenderOnly = 0; }
