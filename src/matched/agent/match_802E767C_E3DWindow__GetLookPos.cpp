struct EVec3 { float x, y, z; };
class E3DWindow {
public:
    char m_pad[640];
    EVec3 m_lookPos;
    EVec3 *GetLookPos();
};
EVec3 *E3DWindow::GetLookPos() { return &m_lookPos; }
