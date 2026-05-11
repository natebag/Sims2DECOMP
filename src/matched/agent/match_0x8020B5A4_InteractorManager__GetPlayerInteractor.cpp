// 0x8020B5A4 InteractorModule::InteractorManager::GetPlayerInteractor(int, InteractorModule::InteractorType) (104B)

namespace InteractorModule {

struct PlayerEntry {
    int m_type;
    void* m_interactor;
};

struct InteractorManager {
    char _pad[28];
    PlayerEntry* m_playerArray;

    bool IsValidPlayerId(int playerId) const;
    void* GetPlayerInteractor(int playerId, int type);
};

void* InteractorManager::GetPlayerInteractor(int playerId, int type) {
    if (!IsValidPlayerId(playerId)) return 0;
    PlayerEntry* entry = &m_playerArray[playerId];
    if (type == -1 || entry->m_type == type) {
        return entry->m_interactor;
    }
    return 0;
}

}
