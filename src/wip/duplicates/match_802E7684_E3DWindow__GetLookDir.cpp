struct EVec3 { float x, y, z; };
class E3DWindow {
public:
    char m_pad[656];
    EVec3 m_lookDir;
    EVec3 *GetLookDir();
};
EVec3 *E3DWindow::GetLookDir() { return &m_lookDir; }
