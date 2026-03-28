// 0x8003DDA0 (8 bytes) — lwz r3, 0x128(r3); blr

class GameData {
public:
    char _pad[0x128];
    void* m_buildBuyPlayer;

    void* GetBuildBuyPlayer() const;
};

void* GameData::GetBuildBuyPlayer() const {
    return m_buildBuyPlayer;
}
