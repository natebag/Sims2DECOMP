// 0x802E294C (8 bytes)
class EApp {
public:
    int GetFullArgString();
};

int EApp::GetFullArgString() {
    return (int)((char*)this + 0x350);
}
