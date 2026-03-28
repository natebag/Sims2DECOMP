/* Behavior::GetTreeIDByNameFast(char *) at 0x800AC470 (52B) */

struct Vt_Behavior_GetTreeIDByNameFast { char pad[0x48]; short m_off; int (*m_fn)(void *, char *); };
struct S_Behavior_GetTreeIDByNameFast { Vt_Behavior_GetTreeIDByNameFast *m_vt; int func(char *name); };

int S_Behavior_GetTreeIDByNameFast::func(char *name) {
    Vt_Behavior_GetTreeIDByNameFast *vt = m_vt;
    short off = vt->m_off;
    return vt->m_fn((char *)this + off, name);
}
