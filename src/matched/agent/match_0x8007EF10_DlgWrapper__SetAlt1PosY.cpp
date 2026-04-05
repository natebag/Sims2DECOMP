/* DlgWrapper::SetAlt1PosY(float) at 0x8007EF10 (80B) */

extern void DW_updA1Y(void *, int);

struct DWVtA1Y { char pad[0x58]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct DWSubA1Y { char pad[0x1C]; DWVtA1Y *m_sub; };
struct DWBaseA1Y { char pad[0x48]; DWSubA1Y *m_btn; };

struct DlgWrapSA1PY {
    char pad[0xAC];
    DWBaseA1Y *m_base;
    void SetAlt1PosY(float y);
};

void DlgWrapSA1PY::SetAlt1PosY(float y) {
    DWBaseA1Y *base = m_base;
    DWSubA1Y *btn = base->m_btn;
    DWVtA1Y *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, y);
    DW_updA1Y(base, 2);
}
