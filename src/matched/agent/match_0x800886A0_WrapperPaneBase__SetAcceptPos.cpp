/* WrapperPaneBase::SetAcceptPos(EVec2 &) at 0x800886A0 (92B) */

extern void WPB_updAX(void *, int);
extern void WPB_updAY(void *, int);

struct BVtP0 { char pad[0x38]; short m_off; char _p[2]; void (*m_fn)(void *, void *); };
struct BSubP0 { char pad[0x1C]; BVtP0 *m_sub; };

struct WPBSAP {
    char pad[0x40];
    BSubP0 *m_btn;
    void SetAcceptPos(void *vec);
};

void WPBSAP::SetAcceptPos(void *vec) {
    BSubP0 *btn = m_btn;
    BVtP0 *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, void *) = sub->m_fn;
    fn((char *)btn + off, vec);
    WPB_updAX(this, 0);
    WPB_updAY(this, 0);
}
