extern int gGameData2[];
void GD_UseConfig(void *);

void GameData_UseConfigOptions(void) {
    GD_UseConfig(gGameData2);
}
