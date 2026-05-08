// FLAGS: -fno-schedule-insns
// 0x80014028 (40 bytes)
// AwarenessManager::GetPlayerObject(int) — indexes _globals.playerObjects[idx]

struct Globals {
    char pad[188];
    void* playerObjects[16];
};

extern "C" Globals _globals;

class AwarenessManager {
public:
    void* GetPlayerObject(int idx);
};

void* AwarenessManager::GetPlayerObject(int idx) {
    void* result = 0;
    void* obj = _globals.playerObjects[idx];
    if (obj != 0) {
        result = *(void**)obj;
    }
    return result;
}
