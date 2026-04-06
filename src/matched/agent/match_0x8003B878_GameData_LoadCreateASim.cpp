// GameData::LoadCreateASim(int, int)
// Address: 0x8003B878 | Size: 40 bytes

struct GameData;

// SDA global GameData instance at 0x80475B84
// Accessed via r13-relative addressing
extern GameData g_gameData;

extern void LoadCreateASim(GameData* data);

void GameData_LoadCreateASim() {
    LoadCreateASim(&g_gameData);
}
