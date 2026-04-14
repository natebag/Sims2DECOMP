/* DlgWrapper::SetAlt1PosX(float) at 0x8007EEC0 (80B) */

extern void DW_updA1X(void *, int);

struct DWVtA1X { char pad[0x48]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct DWSubA1X { char pad[0x1C]; DWVtA1X *m_sub; };
struct DWBaseA1 { char pad[0x48]; DWSubA1X *m_btn; };

struct DlgWrapSA1PX {
    char pad[0xAC];
    DWBaseA1 *m_base;
    void SetAlt1PosX(float x);
};

void DlgWrapSA1PX::SetAlt1PosX(float x) {
    DWBaseA1 *base = m_base;
    DWSubA1X *btn = base->m_btn;
    DWVtA1X *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, x);
    DW_updA1X(base, 2);
}
