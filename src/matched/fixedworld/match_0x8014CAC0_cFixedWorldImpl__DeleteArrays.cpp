// 0x8014CAC0 cFixedWorldImpl::DeleteArrays(void) (188B)

extern void _c2DArray_dtor(void* self, int in_charge);
extern void InfluenceMap_dtor(void* self, int in_charge);
extern void PassiveInfluenceMap_dtor(void* self, int in_charge);

class cFixedWorldImpl {
public:
    char pad_00[44];
    void* m_arr44;      // 44 — _c2DArray
    void* m_arr48;      // 48 — _c2DArray
    void* m_arr52;      // 52 — _c2DArray
    void* m_arr56;      // 56 — _c2DArray
    void* m_inf60;      // 60 — InfluenceMap
    void* m_pinf64;     // 64 — PassiveInfluenceMap
    void DeleteArrays();
};

void cFixedWorldImpl::DeleteArrays() {
    void* p;
    p = m_arr44;
    if (p != 0) _c2DArray_dtor(p, 3);
    p = m_arr56;
    m_arr44 = 0;
    if (p != 0) _c2DArray_dtor(p, 3);
    p = m_arr48;
    m_arr56 = 0;
    if (p != 0) _c2DArray_dtor(p, 3);
    p = m_arr52;
    m_arr48 = 0;
    if (p != 0) _c2DArray_dtor(p, 3);
    p = m_inf60;
    m_arr52 = 0;
    if (p != 0) InfluenceMap_dtor(p, 3);
    p = m_pinf64;
    m_inf60 = 0;
    if (p != 0) PassiveInfluenceMap_dtor(p, 3);
    m_pinf64 = 0;
}
