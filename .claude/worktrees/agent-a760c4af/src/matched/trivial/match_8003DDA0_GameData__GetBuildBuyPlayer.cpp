// 0x8003DDA0 (8 bytes)
class GameData {
public:
    int GetBuildBuyPlayer();
};

int GameData::GetBuildBuyPlayer() {
    return *(int*)((char*)this + 0x128);
}
