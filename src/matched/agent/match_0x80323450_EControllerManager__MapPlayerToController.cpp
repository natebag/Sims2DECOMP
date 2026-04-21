// 0x80323450 (24B) EControllerManager::MapPlayerToController(unsigned int, unsigned int)
// Two parallel array writes via shared index: m_controllers[p] = ctrl; m_active[p] = 1.
// Symbol shows args (uint, uint) but second arg is loaded into r5 (pointer slot) then stored.

class EController;

class EControllerManager {
public:
    EController* m_controllers[4];  // offset 0..16
    int          m_active[4];       // offset 16..32
    void MapPlayerToController(unsigned int player, EController* controller);
};

void EControllerManager::MapPlayerToController(unsigned int player, EController* controller) {
    m_controllers[player] = controller;
    m_active[player] = 1;
}
