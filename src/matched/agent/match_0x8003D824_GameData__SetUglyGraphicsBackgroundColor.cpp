// 0x8003D824 GameData::SetUglyGraphicsBackgroundColor() (92B) — twin of SetBlackBG, different const

class EVec3 {
public:
    float x, y, z;
};

extern char g_UglyBG_const_803D1EA0[16];

class GameData {
public:
    static void SetUglyGraphicsBackgroundColor();
};

extern void* g_BGRenderer_SDA;

void GameData::SetUglyGraphicsBackgroundColor() {
    void* mgr = g_BGRenderer_SDA;
    EVec3 color;
    volatile EVec3* pcolor = &color;
    float v = *(volatile float*)g_UglyBG_const_803D1EA0;
    char* vt = *(char**)mgr;
    short adj = *(short*)(vt + 0x48);
    pcolor->z = v;
    pcolor->y = v;
    color.x = v;
    void* fn = *(void**)(vt + 0x4C);
    ((void(*)(void*, EVec3*, int, int))fn)((char*)mgr + adj, &color, 255, 1);
}
