/* DlgWrapper::SetAcceptPosX(float) at 0x8007EB08 (80B) */

extern void DW_updAX(void *, int);

struct DWVtX { char pad[0x48]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct DWSub { char pad[0x1C]; DWVtX *m_sub; };
struct DWBase { char pad[0x40]; DWSub *m_btn; };

struct DlgWrapSAPX {
    char pad[0xAC];
    DWBase *m_base;
    void SetAcceptPosX(float x);
};

void DlgWrapSAPX::SetAcceptPosX(float x) {
    DWBase *base = m_base;
    DWSub *btn = base->m_btn;
    DWVtX *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, x);
    DW_updAX(base, 0);
}
