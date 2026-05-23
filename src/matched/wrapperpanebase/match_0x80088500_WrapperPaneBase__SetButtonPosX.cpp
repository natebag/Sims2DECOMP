extern void WPB_BtnUpdate(void *, int);

struct BVtPX { char pad[0x48]; short m_delta; char _p[2]; void (*m_fn)(void *, float); };
struct BtnSub { char pad[0x1C]; BVtPX *m_vt; };

struct WPB_SBPX {
    char _pad[0x40];
    BtnSub *m_buttons[4];

    void SetButtonPosX(int btnType, float val);
};

void WPB_SBPX::SetButtonPosX(int btnType, float val) {
    BtnSub *btn = m_buttons[btnType];
    BVtPX *vt = btn->m_vt;
    short delta = vt->m_delta;
    void (*fn)(void *, float) = vt->m_fn;
    fn((char *)btn + delta, val);
    WPB_BtnUpdate(this, btnType);
}
