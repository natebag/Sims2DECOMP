// 0x8003D7C8 GameData::SetBlackGraphicsBackgroundColor() (92B)

class EVec3 {
public:
    float x, y, z;
};

extern char g_BlackBG_const_803D1E9C[16];

class GameData {
public:
    static void SetBlackGraphicsBackgroundColor();
};

extern void* g_BGRenderer_SDA;

void GameData::SetBlackGraphicsBackgroundColor() {
    void* mgr = g_BGRenderer_SDA;
    EVec3 color;
    volatile EVec3* pcolor = &color;
    float v = *(volatile float*)g_BlackBG_const_803D1E9C;
    char* vt = *(char**)mgr;
    short adj = *(short*)(vt + 0x48);
    pcolor->z = v;
    pcolor->y = v;
    color.x = v;
    void* fn = *(void**)(vt + 0x4C);
    ((void(*)(void*, EVec3*, int, int))fn)((char*)mgr + adj, &color, 255, 1);
}
