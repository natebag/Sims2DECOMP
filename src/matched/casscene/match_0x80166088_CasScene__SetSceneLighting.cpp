// 0x80166088 CasScene::SetSceneLighting(int, bool) (72B)

class ELights;

class CasTweakTool {
public:
    void GetLights(ELights& lights);
};

extern char g_CasTweakTool_80487870[16];

class CasScene {
public:
    void SetLights(int n);
    void SetSceneLighting(int n, bool b);
};

void CasScene::SetSceneLighting(int n, bool b) {
    SetLights(n);
    if (b) {
        ((CasTweakTool*)g_CasTweakTool_80487870)->GetLights(*(ELights*)((char*)this + 8));
    }
}
