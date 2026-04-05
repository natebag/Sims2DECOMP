/* DlgWrapper::SetDeclinePosY(float) at 0x8007ED34 (80B) */

extern void DW_updDY(void *, int);

struct DWVtDY { char pad[0x58]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct DWSubDY { char pad[0x1C]; DWVtDY *m_sub; };
struct DWBaseDY { char pad[0x44]; DWSubDY *m_btn; };

struct DlgWrapSDPY {
    char pad[0xAC];
    DWBaseDY *m_base;
    void SetDeclinePosY(float y);
};

void DlgWrapSDPY::SetDeclinePosY(float y) {
    DWBaseDY *base = m_base;
    DWSubDY *btn = base->m_btn;
    DWVtDY *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, y);
    DW_updDY(base, 1);
}
