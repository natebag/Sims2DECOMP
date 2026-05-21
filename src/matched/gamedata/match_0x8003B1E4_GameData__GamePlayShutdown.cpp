// 0x8003B1E4 (72B) GameData::GamePlayShutdown()
// Tech #17 sda21-ha-lo-declaration-control: char[16] forces HA/LO

extern char g_state_0x80475E94[16];     // out-of-SDA → lis+stw
extern char* g_singleton_FFFFAC1C;      // SDA r13-21476 (small)

extern "C" void func_0x800CCE18(void);

class GameData {
public:
    void GamePlayShutdown();
};

void GameData::GamePlayShutdown() {
    *(int*)g_state_0x80475E94 = 0;
    char* obj = g_singleton_FFFFAC1C;
    char* vt = *(char**)obj;
    short adj = *(short*)(vt + 400);
    void* fn = *(void**)(vt + 404);
    ((void (*)(void*))fn)(obj + adj);
    func_0x800CCE18();
}
