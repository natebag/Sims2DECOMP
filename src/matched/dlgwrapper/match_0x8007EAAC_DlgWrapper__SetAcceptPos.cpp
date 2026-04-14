/* DlgWrapper::SetAcceptPos(EVec2 &) at 0x8007EAAC (92B) */

extern void DW_uAX(void *, int);
extern void DW_uAY(void *, int);

struct DWVtPA { char pad[0x38]; short m_off; char _p[2]; void (*m_fn)(void *, void *); };
struct DWSubPA { char pad[0x1C]; DWVtPA *m_sub; };
struct DWBasePA { char pad[0x40]; DWSubPA *m_btn; };

struct DlgWrapSAP {
    char pad[0xAC];
    DWBasePA *m_base;
    void SetAcceptPos(void *vec);
};

void DlgWrapSAP::SetAcceptPos(void *vec) {
    DWBasePA *base = m_base;
    DWSubPA *btn = base->m_btn;
    DWVtPA *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, void *) = sub->m_fn;
    fn((char *)btn + off, vec);
    DW_uAX(base, 0);
    DW_uAY(base, 0);
}
