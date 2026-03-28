struct EVec3 { float x, y, z; };
class E3DWindow {
public:
    char m_pad[160];
    EVec3 m_lookAt;
    EVec3 *GetLookAt();
};
EVec3 *E3DWindow::GetLookAt() { return &m_lookAt; }
