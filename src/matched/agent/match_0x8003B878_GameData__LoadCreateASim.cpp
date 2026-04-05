extern int gGameData[];
void GD_LoadCAS(void *);

void GameData_LoadCreateASim(int a, int b) {
    GD_LoadCAS(gGameData);
}
