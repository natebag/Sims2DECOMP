// 0x80090E04 (8 bytes)
class LoadingScreenStateMachine {
public:
    int GetLoadingScreen();
};

int LoadingScreenStateMachine::GetLoadingScreen() {
    return *(int*)((char*)this + 0x98);
}
