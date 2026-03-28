// 0x802E767C (8 bytes)
class E3DWindow {
public:
    int GetLookPos();
};

int E3DWindow::GetLookPos() {
    return (int)((char*)this + 0x280);
}
