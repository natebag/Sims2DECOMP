/* IFFBehaviorTree::GetFromDataID(ObjectDataID) at 0x8015B61C (52B) */

struct Vt_IFFBehaviorTree_GetFromDataID { char pad[0x28]; short m_off; int (*m_fn)(void *, int); };
struct S_IFFBehaviorTree_GetFromDataID { Vt_IFFBehaviorTree_GetFromDataID *m_vt; int func(int id); };

int S_IFFBehaviorTree_GetFromDataID::func(int id) {
    Vt_IFFBehaviorTree_GetFromDataID *vt = m_vt;
    short off = vt->m_off;
    return vt->m_fn((char *)this + off, id);
}
