// 0x802E769C (8 bytes)
class E3DWindow {
public:
    int GetNormalizedProjection();
};

int E3DWindow::GetNormalizedProjection() {
    return (int)((char*)this + 0x1E0);
}
