// 0x8003B8A0 GameData::SaveCreateASim() (88B)
// Tech #47 chained MI vcall through SDA globals

extern char* g_gd_mgr;        // SDA -0x53E4
extern char* g_save_arg1;     // SDA -0x7D38
extern char* g_save_arg2;     // SDA -0x7D28

class GameData {
public:
    static void SaveCreateASim();
};

void GameData::SaveCreateASim() {
    char* mgr = g_gd_mgr;
    char* vt = *(char**)mgr;
    void* (*fn1)(void*) = *(void* (**)(void*))(vt + 0x194);
    short adj1 = *(short*)(vt + 0x190);
    char* result = (char*)fn1(mgr + adj1);

    char* vt2 = *(char**)result;
    char* a1 = g_save_arg1;
    short adj2 = *(short*)(vt2 + 0x68);
    void* (*fn2)(void*, char*, char*) = *(void* (**)(void*, char*, char*))(vt2 + 0x6C);
    char* a2 = g_save_arg2;
    fn2(result + adj2, a1, a2);
}
