struct EMat4 { float m[16]; };
class E3DWindow {
public:
    char m_pad[480];
    EMat4 m_normalizedProjection;
    EMat4 *GetNormalizedProjection() const;
};
EMat4 *E3DWindow::GetNormalizedProjection() const { return (EMat4 *)&m_normalizedProjection; }
