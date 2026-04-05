extern void WPB_BtnUpdate(void *, int);

struct BVtPY { char pad[0x58]; short m_delta; char _p[2]; void (*m_fn)(void *, float); };
struct BtnSubY { char pad[0x1C]; BVtPY *m_vt; };

struct WPB_SBPY {
    char _pad[0x40];
    BtnSubY *m_buttons[4];

    void SetButtonPosY(int btnType, float val);
};

void WPB_SBPY::SetButtonPosY(int btnType, float val) {
    BtnSubY *btn = m_buttons[btnType];
    BVtPY *vt = btn->m_vt;
    short delta = vt->m_delta;
    void (*fn)(void *, float) = vt->m_fn;
    fn((char *)btn + delta, val);
    WPB_BtnUpdate(this, btnType);
}
