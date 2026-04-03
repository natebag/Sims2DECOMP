// 0x801672B8 (8 bytes)
class CasScene {
public:
    int Get3DWindow();
};

int CasScene::Get3DWindow() {
    return *(int*)((char*)this + 0xB18);
}
