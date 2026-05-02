// 0x80352998 Effects::EffectsManager::ForEachEffectInList(EffectsVisitor&, TNodeList<EffectEntry*>&) (120B)
//
// Cracked S13 Lane F-1 (2026-05-02) via SOURCE-LEVEL recipe — NO mutator
// needed. The mi_thisoffset_dispatch wall premise turned out to be an
// MI-vcall pattern that natural source structure already produces correctly.
// Key insight: this is a NON-STATIC member function (r3=this/unused, r4=visitor&,
// r5=list&), and the MI-vcall through `add r3, effect, vt->m_off; mtlr fn; blrl`
// matches DOL byte-exactly when the source treats effect+offset as the adjusted
// `this` argument explicitly.
//
// Triage outcome: descopes mi_thisoffset_dispatch mutator (catalog entry pending).

namespace Effects {

struct EffectsVisitor;

struct VisitorVt {
    char pad[0x28];
    short m_off;
    char _p[2];
    int (*m_fn)(void*, EffectsVisitor*);
};

class Effect {
public:
    char pad[0x144];
    VisitorVt* m_vt;
};

namespace EffectsManagerNS {
struct EffectEntry {
    char pad[8];
    Effect* m_effect;
};
}

class EffectsManager {
public:
    typedef EffectsManagerNS::EffectEntry EffectEntry;
    int ForEachEffectInList(EffectsVisitor& visitor, void* list_head_ptr);
};

}

struct ListNode {
    Effects::EffectsManager::EffectEntry* m_data;  // 0x00
    char pad[4];                                   // 0x04
    ListNode* m_next;                              // 0x08
};

struct TNodeList {
    ListNode* m_head;
};

int Effects::EffectsManager::ForEachEffectInList(EffectsVisitor& visitor, void* list_head_ptr) {
    TNodeList& list = *(TNodeList*)list_head_ptr;
    ListNode* node = list.m_head;
    while (node != 0) {
        Effect* effect = node->m_data->m_effect;
        VisitorVt* vt = effect->m_vt;
        short off = vt->m_off;
        int (*fn)(void*, EffectsVisitor*) = vt->m_fn;
        int r = fn((char*)effect + off, &visitor);
        if (r == 0) return 0;
        node = node->m_next;
    }
    return 1;
}
