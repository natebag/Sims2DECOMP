/* DlgWrapper::SetDeclinePosX(float) at 0x8007ECE4 (80B) */

extern void DW_updDX(void *, int);

struct DWVtDX { char pad[0x48]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct DWSubDX { char pad[0x1C]; DWVtDX *m_sub; };
struct DWBaseDX { char pad[0x44]; DWSubDX *m_btn; };

struct DlgWrapSDPX {
    char pad[0xAC];
    DWBaseDX *m_base;
    void SetDeclinePosX(float x);
};

void DlgWrapSDPX::SetDeclinePosX(float x) {
    DWBaseDX *base = m_base;
    DWSubDX *btn = base->m_btn;
    DWVtDX *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, x);
    DW_updDX(base, 1);
}
