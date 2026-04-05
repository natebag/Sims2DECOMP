/* WrapperPaneBase::SetAcceptPosX(float) at 0x800886FC (80B) */

extern void WPB_update(void *, int);

struct BVtX { char pad[0x48]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct BSub { char pad[0x1C]; BVtX *m_sub; };

struct WPBSAPX {
    char pad[0x40];
    BSub *m_btn;
    void SetAcceptPosX(float x);
};

void WPBSAPX::SetAcceptPosX(float x) {
    BSub *btn = m_btn;
    BVtX *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, x);
    WPB_update(this, 0);
}
