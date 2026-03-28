class EGraphics {
public:
    char m_pad[796];
    int m_firstPassRenderOnly;
    void EnableFirstPassRender();
};
void EGraphics::EnableFirstPassRender() { m_firstPassRenderOnly = 1; }
