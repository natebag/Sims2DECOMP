// 0x80097D44 TheSimsSimsIntroMovieState::Shutdown (72b)

struct GameData;
extern GameData g_gameData;

extern int g_allowControllerReading;
extern int g_allowInputProcessing;

struct TheSimsSimsIntroMovieState {
    char pad[0x24];
    int field_24;

    void Shutdown();
};

void GameData_SetUglyGraphicsBackgroundColor(GameData*);

void TheSimsSimsIntroMovieState::Shutdown() {
    if (field_24 != 0) {
        g_allowControllerReading = 1;
        g_allowInputProcessing = 1;
        field_24 = 0;
    }
    GameData_SetUglyGraphicsBackgroundColor(&g_gameData);
}
