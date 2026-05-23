// 0x80352798 (56B) Effects::EffectsManager::ScheduleEffectForDeletion(EffectEntry *)
// Early-out if already pending; otherwise mark + AddEntryToList(e, m_pendingDeletes).

namespace Effects {

class Effect;

class EffectsManager {
public:
    struct EffectEntry {
        char pad[4];
        int  m_pendingFlag;   // offset 4
    };

    class ENodeList { public: void AddTail(unsigned int); };
    template<class T> class TNodeList : public ENodeList {};

    char pad[0x10];
    TNodeList<EffectEntry*> m_pendingDeletes;   // offset 0x10

    bool AddEntryToList(EffectEntry* e, TNodeList<EffectEntry*>& list);
    void ScheduleEffectForDeletion(EffectEntry* e);
};

void EffectsManager::ScheduleEffectForDeletion(EffectEntry* e) {
    if (e->m_pendingFlag != 0) return;
    e->m_pendingFlag = 1;
    AddEntryToList(e, m_pendingDeletes);
}

}  // namespace Effects
