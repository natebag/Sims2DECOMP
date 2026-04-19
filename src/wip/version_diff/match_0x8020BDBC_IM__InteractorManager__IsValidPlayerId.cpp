/* InteractorModule::InteractorManager::IsValidPlayerId(int) const at 0x8020BDBC (56B) */

struct IM_IManager_IVP {
    void* m_players;
    int m_count;
    int IsValidPlayerId(int id) const;
};

int IM_IManager_IVP::IsValidPlayerId(int id) const {
    if (!m_players) return 0;
    if (id < 0) return 0;
    if (id >= m_count) return 0;
    if (id > 7) return 0;
    return 1;
}
