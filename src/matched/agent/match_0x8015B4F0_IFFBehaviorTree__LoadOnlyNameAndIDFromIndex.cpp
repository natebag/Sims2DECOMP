/* IFFBehaviorTree::LoadOnlyNameAndIDFromIndex(unsigned int) at 0x8015B4F0 (52B) */

struct Vt_IFFBehaviorTree_LoadOnlyNameAndIDFromIndex { char pad[0x30]; short m_off; int (*m_fn)(void *, unsigned int); };
struct S_IFFBehaviorTree_LoadOnlyNameAndIDFromIndex { Vt_IFFBehaviorTree_LoadOnlyNameAndIDFromIndex *m_vt; int func(unsigned int idx); };

int S_IFFBehaviorTree_LoadOnlyNameAndIDFromIndex::func(unsigned int idx) {
    Vt_IFFBehaviorTree_LoadOnlyNameAndIDFromIndex *vt = m_vt;
    short off = vt->m_off;
    return vt->m_fn((char *)this + off, idx);
}
