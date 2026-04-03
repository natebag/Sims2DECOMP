// 0x802E7694 (8 bytes)
class E3DWindow {
public:
    int GetProjection();
};

int E3DWindow::GetProjection() {
    return (int)((char*)this + 0x160);
}
