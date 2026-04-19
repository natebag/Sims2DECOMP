/* InteractorModule::InteractorManager::IsValidPlayerId(int) const at 0x8020BDBC (56B) */

struct InteractorMgr_IVP {
    int numPlayers;
    int maxPlayerId;
    int IsValidPlayerId(int playerId) const;
};

int InteractorMgr_IVP::IsValidPlayerId(int playerId) const {
    if (!numPlayers) return 0;
    if (playerId < 0) return 0;
    if (playerId >= maxPlayerId) return 0;
    if (playerId > 7) return 0;
    return 1;
}
