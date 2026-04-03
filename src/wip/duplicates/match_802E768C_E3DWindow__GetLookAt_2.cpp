// 0x802E768C (8 bytes)
class E3DWindow {
public:
    int GetLookAt();
};

int E3DWindow::GetLookAt() {
    return (int)((char*)this + 0xA0);
}
