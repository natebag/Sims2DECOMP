// 0x80005410 (8 bytes)
class ESimsApp {
public:
    void SetGameState(int p);
};

void ESimsApp::SetGameState(int p) {
    *(int*)((char*)this + 0x468) = p;
}
