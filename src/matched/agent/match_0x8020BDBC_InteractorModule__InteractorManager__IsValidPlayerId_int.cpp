// 0x8020BDBC InteractorModule::InteractorManager::IsValidPlayerId(int) (56 B)

struct InteractorManager {
    int m_field0;
    int m_maxPlayers;

    int IsValidPlayerId(int playerId);
};

int InteractorManager::IsValidPlayerId(int playerId) {
    if (m_field0 != 0) goto checks;
ret0:
    return 0;
checks:
    if (playerId < 0) goto ret0;
    if (playerId >= m_maxPlayers) goto ret0;
    if (playerId > 7) goto ret0;
    return 1;
}
