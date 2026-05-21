// 0x8032362C (64B) EControllerManager::GetPlayerController(unsigned int)

extern void* EControllerManager_table[4];  // 0x804FCF78

class EControllerManager {
public:
    int GetPlayerControllerIndex(unsigned int idx);  // 0x80323610
    void* GetPlayerController(unsigned int idx);
};

void* EControllerManager::GetPlayerController(unsigned int idx) {
    int i = GetPlayerControllerIndex(idx);
    if (i == -1) return 0;
    return EControllerManager_table[i];
}
