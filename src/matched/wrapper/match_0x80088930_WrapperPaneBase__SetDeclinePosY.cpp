/* WrapperPaneBase::SetDeclinePosY(float) at 0x80088930 (80B) */

extern void WPB_updateDY(void *, int);

struct BVtDY { char pad[0x58]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct BSubDY { char pad[0x1C]; BVtDY *m_sub; };

struct WPBSDPY {
    char pad[0x44];
    BSubDY *m_btn;
    void SetDeclinePosY(float y);
};

void WPBSDPY::SetDeclinePosY(float y) {
    BSubDY *btn = m_btn;
    BVtDY *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, y);
    WPB_updateDY(this, 1);
}
