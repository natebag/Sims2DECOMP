// 0x8003DA5C GameData::StageStartFrame() (68B) — Tech #47 MI-vcall via SDA mgr

extern void* g_managerHolder_SDA;
extern float g_resultSlot_SDA;
extern char g_arg_804AD210[16];

class GameData {
public:
    static void StageStartFrame();
};

void GameData::StageStartFrame() {
    char* mgr = (char*)g_managerHolder_SDA;
    char* vt = *(char**)mgr;

    short adj = *(short*)(vt + 40);
    void* fn = *(void**)(vt + 44);
    g_resultSlot_SDA = ((float(*)(void*, char*))fn)(mgr + adj, g_arg_804AD210);
}
