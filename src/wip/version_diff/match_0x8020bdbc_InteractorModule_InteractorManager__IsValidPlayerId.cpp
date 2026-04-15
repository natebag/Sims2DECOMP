// 0x8020BDBC InteractorModule::InteractorManager::IsValidPlayerId(int) const (56B)

struct InteractorModule_InteractorManager {
    void* m_players;
    int m_playerCount;
    int IsValidPlayerId(int id) const;
};

int InteractorModule_InteractorManager::IsValidPlayerId(int id) const {
    if (m_players) {
        if (id >= 0) {
            if (id < m_playerCount) {
                if (id <= 7) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
