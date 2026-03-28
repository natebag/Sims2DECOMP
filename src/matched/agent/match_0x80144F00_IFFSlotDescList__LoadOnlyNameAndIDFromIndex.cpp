/* IFFSlotDescList::LoadOnlyNameAndIDFromIndex(unsigned int) at 0x80144F00 (52B) */

struct Vt_IFFSlotDescList_LoadOnlyNameAndIDFromIndex { char pad[0x30]; short m_off; int (*m_fn)(void *, unsigned int); };
struct S_IFFSlotDescList_LoadOnlyNameAndIDFromIndex { Vt_IFFSlotDescList_LoadOnlyNameAndIDFromIndex *m_vt; int func(unsigned int idx); };

int S_IFFSlotDescList_LoadOnlyNameAndIDFromIndex::func(unsigned int idx) {
    Vt_IFFSlotDescList_LoadOnlyNameAndIDFromIndex *vt = m_vt;
    short off = vt->m_off;
    return vt->m_fn((char *)this + off, idx);
}
