/* DlgWrapper::SetAcceptPosY(float) at 0x8007EB58 (80B) */

extern void DW_updAY(void *, int);

struct DWVtY1 { char pad[0x58]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct DWSub1 { char pad[0x1C]; DWVtY1 *m_sub; };
struct DWBase1 { char pad[0x40]; DWSub1 *m_btn; };

struct DlgWrapSAPY {
    char pad[0xAC];
    DWBase1 *m_base;
    void SetAcceptPosY(float y);
};

void DlgWrapSAPY::SetAcceptPosY(float y) {
    DWBase1 *base = m_base;
    DWSub1 *btn = base->m_btn;
    DWVtY1 *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, y);
    DW_updAY(base, 0);
}
