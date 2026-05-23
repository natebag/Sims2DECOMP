// 0x80352910 (64B) Effects::EffectsManager::FindEffectInList(Effect *, TNodeList<...> &, NLIteratorPtrType **)
// Leaf list-search: walk list.head via node->next (offset 8); if entry->effect2 == target,
// store node into *outIter (if non-null), return entry. cr7-hoisted outIter check.

namespace Effects {

class Effect;

class EffectsManager {
public:
    struct EffectEntry {
        Effect* effect1;        // offset 0
        char    pad[4];
        Effect* effect2;        // offset 8 — search key
    };

    struct Node {
        void* data;             // offset 0
        char  pad[4];
        Node* next;             // offset 8
    };

    class ENodeList {
    public:
        Node* m_head;           // offset 0
    };

    template<class T> class TNodeList : public ENodeList {};

    typedef void* NLIteratorPtrType;

    EffectEntry* FindEffectInList(Effect* target, TNodeList<EffectEntry*>& list, NLIteratorPtrType** outIter);
};

EffectsManager::EffectEntry* EffectsManager::FindEffectInList(
    Effect* target, TNodeList<EffectEntry*>& list, NLIteratorPtrType** outIter)
{
    Node* node = list.m_head;
    while (node != 0) {
        EffectEntry* entry = (EffectEntry*)node->data;
        if (entry->effect2 == target) {
            if (outIter != 0) *outIter = (NLIteratorPtrType*)node;
            return entry;
        }
        node = node->next;
    }
    return 0;
}

}  // namespace Effects
