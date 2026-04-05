/* WrapperPaneBase::SetDeclinePosX(float) at 0x800888E0 (80B) */

extern void WPB_updateDX(void *, int);

struct BVtDX { char pad[0x48]; short m_off; char _p[2]; void (*m_fn)(void *, float); };
struct BSubDX { char pad[0x1C]; BVtDX *m_sub; };

struct WPBSDPX {
    char pad[0x44];
    BSubDX *m_btn;
    void SetDeclinePosX(float x);
};

void WPBSDPX::SetDeclinePosX(float x) {
    BSubDX *btn = m_btn;
    BVtDX *sub = btn->m_sub;
    short off = sub->m_off;
    void (*fn)(void *, float) = sub->m_fn;
    fn((char *)btn + off, x);
    WPB_updateDX(this, 1);
}
