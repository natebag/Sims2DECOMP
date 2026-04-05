/* WrapperPaneBase::SetAlt1PosX(float) at 0x80088AC4 (80B) */

extern void WPB_updateAX(void *, int);

struct BVtAX { char pad[0x48]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct BSubAX { char pad[0x1C]; BVtAX *m_sub; };

struct WPBSA1PX {
    char pad[0x48];
    BSubAX *m_btn;
    void SetAlt1PosX(float x);
};

void WPBSA1PX::SetAlt1PosX(float x) {
    BSubAX *btn = m_btn;
    BVtAX *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, x);
    WPB_updateAX(this, 2);
}
