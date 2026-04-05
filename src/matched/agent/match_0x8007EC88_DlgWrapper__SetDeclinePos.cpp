/* DlgWrapper::SetDeclinePos(EVec2 &) at 0x8007EC88 (92B) */

extern void DW_uDX(void *, int);
extern void DW_uDY(void *, int);

struct DWVtPD { char pad[0x38]; short m_off; char _p[2]; void (*m_fn)(void *, void *); };
struct DWSubPD { char pad[0x1C]; DWVtPD *m_sub; };
struct DWBasePD { char pad[0x44]; DWSubPD *m_btn; };

struct DlgWrapSDP {
    char pad[0xAC];
    DWBasePD *m_base;
    void SetDeclinePos(void *vec);
};

void DlgWrapSDP::SetDeclinePos(void *vec) {
    DWBasePD *base = m_base;
    DWSubPD *btn = base->m_btn;
    DWVtPD *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, void *) = sub->m_fn;
    fn((char *)btn + off, vec);
    DW_uDX(base, 1);
    DW_uDY(base, 1);
}
