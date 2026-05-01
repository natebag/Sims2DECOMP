// 0x80352860 (52B) Effects::EffectsManager::AddEntryToList(EffectEntry*, TNodeList<EffectEntry*>&)
// Returns 0 if entry is null, else list.AddTail((unsigned int)entry); return 1.

namespace Effects {

class EffectsManager {
public:
    struct EffectEntry { char pad[4]; int m_pendingFlag; };

    class ENodeList { public: void AddTail(unsigned int); };
    template<class T> class TNodeList : public ENodeList {};

    int AddEntryToList(EffectEntry* e, TNodeList<EffectEntry*>& list);
};

int EffectsManager::AddEntryToList(EffectEntry* e, TNodeList<EffectEntry*>& list) {
    if (e == 0) return 0;
    list.AddTail((unsigned int)e);
    return 1;
}

}  // namespace Effects
