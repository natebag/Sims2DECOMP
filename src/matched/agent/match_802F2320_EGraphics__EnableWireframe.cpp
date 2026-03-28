class EGraphics {
public:
    char m_pad[792];
    int m_wireframe;
    void EnableWireframe(bool);
};
void EGraphics::EnableWireframe(bool enable) { m_wireframe = enable; }
