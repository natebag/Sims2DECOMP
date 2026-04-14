/* WrapperPaneBase::SetDeclinePos(EVec2 &) at 0x80088884 (92B) */

extern void WPB_updDX(void *, int);
extern void WPB_updDY(void *, int);

struct BVtPD { char pad[0x38]; short m_off; char _p[2]; void (*m_fn)(void *, void *); };
struct BSubPD { char pad[0x1C]; BVtPD *m_sub; };

struct WPBSDP {
    char pad[0x44];
    BSubPD *m_btn;
    void SetDeclinePos(void *vec);
};

void WPBSDP::SetDeclinePos(void *vec) {
    BSubPD *btn = m_btn;
    BVtPD *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, void *) = sub->m_fn;
    fn((char *)btn + off, vec);
    WPB_updDX(this, 1);
    WPB_updDY(this, 1);
}
