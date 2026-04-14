/* DlgWrapper::SetAlt1Pos(EVec2 &) at 0x8007EE64 (92B) */

extern void DW_uA1X(void *, int);
extern void DW_uA1Y(void *, int);

struct DWVtP1 { char pad[0x38]; short m_off; char _p[2]; void (*m_fn)(void *, void *); };
struct DWSubP1 { char pad[0x1C]; DWVtP1 *m_sub; };
struct DWBaseP1 { char pad[0x48]; DWSubP1 *m_btn; };

struct DlgWrapSA1P {
    char pad[0xAC];
    DWBaseP1 *m_base;
    void SetAlt1Pos(void *vec);
};

void DlgWrapSA1P::SetAlt1Pos(void *vec) {
    DWBaseP1 *base = m_base;
    DWSubP1 *btn = base->m_btn;
    DWVtP1 *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, void *) = sub->m_fn;
    fn((char *)btn + off, vec);
    DW_uA1X(base, 2);
    DW_uA1Y(base, 2);
}
