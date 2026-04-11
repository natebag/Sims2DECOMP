// GameData::UseConfigOptions(void)
// Address: 0x8003D880 | Size: 40 bytes

struct GameData;
extern GameData g_gameData;  // SDA global

extern void UseConfigOptions(GameData* data);

void GameData_UseConfigOptions() {
    UseConfigOptions(&g_gameData);
}
