// GameData::LoadCreateASim(int, int)
// Address: 0x8003B878 | Size: 40 bytes
// Pattern: Load global address + call

typedef unsigned int uint;

struct GameData;
extern GameData* g_pGameData;

void LoadCreateASim(GameData* gd, int a, int b);

void GameData__LoadCreateASim(int a, int b) {
    LoadCreateASim(g_pGameData, a, b);
}
