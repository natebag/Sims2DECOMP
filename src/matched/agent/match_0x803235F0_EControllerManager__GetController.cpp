// 0x803235F0 EControllerManager::GetController(unsigned int) (32B)

extern void* EControllerManager_table[4];

class EControllerManager {
public:
    void* GetController(int idx);
};

void* EControllerManager::GetController(int idx) {
    void* result = 0;
    if (idx > 3) goto end;
    result = EControllerManager_table[idx];
end:
    return result;
}
