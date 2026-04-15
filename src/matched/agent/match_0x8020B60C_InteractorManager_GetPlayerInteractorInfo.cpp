// 0x8020B60C InteractorModule::InteractorManager::GetPlayerInteractorInfo(int) const (72B)

struct InteractorInfo;

struct InteractorManager {
    char pad[64];
    InteractorInfo* m_playerInfo;
    int IsValidPlayerId(int) const;
    InteractorInfo* GetPlayerInteractorInfo(int playerId) const;
};

InteractorInfo* InteractorManager::GetPlayerInteractorInfo(int playerId) const {
    if (!IsValidPlayerId(playerId)) {
        playerId = 0;
    }
    return (InteractorInfo*)((char*)m_playerInfo + (playerId * 16));
}
