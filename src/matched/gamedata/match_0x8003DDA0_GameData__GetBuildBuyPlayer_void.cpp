// 0x8003DDA0 GameData::GetBuildBuyPlayer(void) (8 B)
struct GameData { char _pad[0x128]; unsigned m_buildBuyPlayer; unsigned GetBuildBuyPlayer(); };
unsigned GameData::GetBuildBuyPlayer() { return m_buildBuyPlayer; }
