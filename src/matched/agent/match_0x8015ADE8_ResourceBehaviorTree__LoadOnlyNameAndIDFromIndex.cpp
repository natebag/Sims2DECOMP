/* ResourceBehaviorTree::LoadOnlyNameAndIDFromIndex(unsigned int) at 0x8015ADE8 (52B) */

struct Vt_ResourceBehaviorTree_LoadOnlyNameAndIDFromIndex { char pad[0x30]; short m_off; int (*m_fn)(void *, unsigned int); };
struct S_ResourceBehaviorTree_LoadOnlyNameAndIDFromIndex { Vt_ResourceBehaviorTree_LoadOnlyNameAndIDFromIndex *m_vt; int func(unsigned int idx); };

int S_ResourceBehaviorTree_LoadOnlyNameAndIDFromIndex::func(unsigned int idx) {
    Vt_ResourceBehaviorTree_LoadOnlyNameAndIDFromIndex *vt = m_vt;
    short off = vt->m_off;
    return vt->m_fn((char *)this + off, idx);
}
