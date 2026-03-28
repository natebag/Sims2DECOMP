// 0x800578A4 (8 bytes)
class CLoadingScreen {
public:
    int GetMode();
};

int CLoadingScreen::GetMode() {
    return *(int*)((char*)this + 0x354);
}
