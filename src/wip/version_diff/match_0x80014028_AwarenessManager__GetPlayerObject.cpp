// AwarenessManager::GetPlayerObject(int)
// Address: 0x80014028 | Size: 40 bytes
// Pattern: Array lookup with bounds check

typedef unsigned int uint;

// Array at 0x80475E88 (from 0x80475DCC + 0xBC)
extern void* g_playerObjects[];

void* AwarenessManager__GetPlayerObject(int index) {
    if (g_playerObjects[index] == 0) return 0;
    return g_playerObjects[index];
}
