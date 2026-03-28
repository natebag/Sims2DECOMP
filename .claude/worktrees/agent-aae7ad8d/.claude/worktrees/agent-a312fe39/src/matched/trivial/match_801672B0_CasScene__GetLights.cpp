// 0x801672B0 (8 bytes)
class CasScene {
public:
    int GetLights();
};

int CasScene::GetLights() {
    return (int)((char*)this + 0x8);
}
