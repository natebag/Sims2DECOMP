/* WrapperPaneBase::SetAcceptPosY(float) at 0x8008874C (80B) */

extern void WPB_updateY(void *, int);

struct BVtY1 { char pad[0x58]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct BSub1 { char pad[0x1C]; BVtY1 *m_sub; };

struct WPBSAPY {
    char pad[0x40];
    BSub1 *m_btn;
    void SetAcceptPosY(float y);
};

void WPBSAPY::SetAcceptPosY(float y) {
    BSub1 *btn = m_btn;
    BVtY1 *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, y);
    WPB_updateY(this, 0);
}
