/* AwarenessManager::GetPlayerObject(int) at 0x80014028 (40B) */

struct AwarenessBase_GPO {
    char _pad[0xbc];
    void* players[];
};
extern AwarenessBase_GPO g_awarenessBase_GPO;

struct AwarenessManager_GPO {
    void* GetPlayerObject(int playerId);
};

void* AwarenessManager_GPO::GetPlayerObject(int playerId) {
    void* result = 0;
    void* entry = g_awarenessBase_GPO.players[playerId];
    if (!entry) return result;
    return *(void**)entry;
}
