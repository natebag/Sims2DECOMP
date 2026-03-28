// 0x802E2954 (8 bytes)
class EApp {
public:
    int GetGameState();
};

int EApp::GetGameState() {
    return *(int*)((char*)this + 0x468);
}
