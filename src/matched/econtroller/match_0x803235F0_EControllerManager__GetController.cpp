// 0x803235F0 EControllerManager::GetController(unsigned int) (32B)

extern void* g_controllers[4];

class EControllerManager {
public:
    void* GetController(int idx) const;
};

void* EControllerManager::GetController(int idx) const {
    void* result = 0;
    if (idx <= 3) result = g_controllers[idx];
    return result;
}
