extern int gGameUpdateFlag;
extern float gDeltaTime;

void UpdateGameFunc1(float dt);
void UpdateGameFunc2(void* obj, float dt);

extern char gSimsApp[];

void ESimsApp_UpdateGame() {
    if (gGameUpdateFlag == 0) {
        UpdateGameFunc1(gDeltaTime);
    }
    UpdateGameFunc2(gSimsApp, gDeltaTime);
}
