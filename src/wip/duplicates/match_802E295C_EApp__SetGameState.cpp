// 0x802E295C (8 bytes)
class EApp {
public:
    void SetGameState(int p);
};

void EApp::SetGameState(int p) {
    *(int*)((char*)this + 0x468) = p;
}
