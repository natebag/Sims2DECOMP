struct EMat4 { float m[16]; };
class E3DWindow {
public:
    char m_pad[352];
    EMat4 m_projection;
    EMat4 *GetProjection() const;
};
EMat4 *E3DWindow::GetProjection() const { return (EMat4 *)&m_projection; }
