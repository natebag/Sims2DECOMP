/* WrapperPaneBase::SetAlt1Pos(EVec2 &) at 0x80088A68 (92B) */

extern void WPB_updA1X(void *, int);
extern void WPB_updA1Y(void *, int);

struct BVtPA { char pad[0x38]; short m_off; char _p[2]; void (*m_fn)(void *, void *); };
struct BSubPA { char pad[0x1C]; BVtPA *m_sub; };

struct WPBSA1P {
    char pad[0x48];
    BSubPA *m_btn;
    void SetAlt1Pos(void *vec);
};

void WPBSA1P::SetAlt1Pos(void *vec) {
    BSubPA *btn = m_btn;
    BVtPA *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, void *) = sub->m_fn;
    fn((char *)btn + off, vec);
    WPB_updA1X(this, 2);
    WPB_updA1Y(this, 2);
}
