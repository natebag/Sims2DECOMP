// 0x80166088 CasScene::SetSceneLighting (72b)

struct ELight;
struct CasScene;

void CasScene_SetLights(CasScene*, int, bool);
void ELight_Configure(ELight*, void*);

extern ELight* g_sceneLight;

struct CasScene {
    char pad[8];
    void* lightConfig;

    void SetSceneLighting(int, bool);
};

void CasScene::SetSceneLighting(int a, bool b) {
    CasScene_SetLights(this, a, b);
    if (b) {
        ELight_Configure(g_sceneLight, lightConfig);
    }
}
