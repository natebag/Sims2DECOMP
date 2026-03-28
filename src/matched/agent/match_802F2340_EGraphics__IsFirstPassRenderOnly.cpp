class EGraphics {
public:
    char m_pad[796];
    int m_firstPassRenderOnly;
    int IsFirstPassRenderOnly();
};
int EGraphics::IsFirstPassRenderOnly() { return m_firstPassRenderOnly; }
