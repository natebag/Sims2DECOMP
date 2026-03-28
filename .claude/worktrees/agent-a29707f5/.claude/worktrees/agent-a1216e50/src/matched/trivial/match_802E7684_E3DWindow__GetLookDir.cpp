// 0x802E7684 (8 bytes)
class E3DWindow {
public:
    int GetLookDir();
};

int E3DWindow::GetLookDir() {
    return (int)((char*)this + 0x290);
}
