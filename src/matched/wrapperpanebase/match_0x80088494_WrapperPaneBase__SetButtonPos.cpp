extern void WPB_BtnUpdateX(void *, int);
extern void WPB_BtnUpdateY(void *, int);

struct BVtPS { char pad[0x38]; short m_delta; char _p[2]; void (*m_fn)(void *, void *); };
struct BtnSubPS { char pad[0x1C]; BVtPS *m_vt; };

struct WPB_SBP {
    char _pad[0x40];
    BtnSubPS *m_buttons[4];

    void SetButtonPos(int btnType, void *vec);
};

void WPB_SBP::SetButtonPos(int btnType, void *vec) {
    BtnSubPS *btn = m_buttons[btnType];
    BVtPS *vt = btn->m_vt;
    short delta = vt->m_delta;
    void (*fn)(void *, void *) = vt->m_fn;
    fn((char *)btn + delta, vec);
    WPB_BtnUpdateX(this, btnType);
    WPB_BtnUpdateY(this, btnType);
}
