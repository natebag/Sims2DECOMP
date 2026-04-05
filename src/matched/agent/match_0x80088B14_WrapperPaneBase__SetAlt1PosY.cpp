/* WrapperPaneBase::SetAlt1PosY(float) at 0x80088B14 (80B) */

extern void WPB_updateAY(void *, int);

struct BVtAY { char pad[0x58]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct BSubAY { char pad[0x1C]; BVtAY *m_sub; };

struct WPBSA1PY {
    char pad[0x48];
    BSubAY *m_btn;
    void SetAlt1PosY(float y);
};

void WPBSA1PY::SetAlt1PosY(float y) {
    BSubAY *btn = m_btn;
    BVtAY *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, y);
    WPB_updateAY(this, 2);
}
