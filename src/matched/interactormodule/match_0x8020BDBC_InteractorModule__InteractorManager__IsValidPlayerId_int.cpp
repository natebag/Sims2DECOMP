// 0x8020BDBC (56B) InteractorModule::InteractorManager::IsValidPlayerId(int) const
// Leaf predicate: 4 conditions chain to single return-0 landing pad.

namespace InteractorModule {

class InteractorManager {
public:
    void* m_instances;
    int m_count;
    int IsValidPlayerId(int playerId) const;
};

}

int InteractorModule::InteractorManager::IsValidPlayerId(int playerId) const {
    if (m_instances == 0) return 0;
    if (playerId < 0 || playerId >= m_count || playerId > 7) return 0;
    return 1;
}
