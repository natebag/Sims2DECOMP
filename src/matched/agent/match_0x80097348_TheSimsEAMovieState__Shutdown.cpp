// 0x80097348 TheSimsEAMovieState::Shutdown (72b)

struct GameData;
extern GameData g_gameData;

extern int g_allowControllerReading;
extern int g_allowInputProcessing;

struct TheSimsEAMovieState {
    char pad[0x1C];
    int field_1C;

    void Shutdown();
};

void GameData_SetUglyGraphicsBackgroundColor(GameData*);

void TheSimsEAMovieState::Shutdown() {
    if (field_1C != 0) {
        g_allowControllerReading = 1;
        g_allowInputProcessing = 1;
        field_1C = 0;
    }
    GameData_SetUglyGraphicsBackgroundColor(&g_gameData);
}
