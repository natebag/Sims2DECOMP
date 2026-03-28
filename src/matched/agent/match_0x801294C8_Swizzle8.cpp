
void SetHilite_Func1(void *, int);
void SetHilite_Func2(void *, int);

struct SetHiliteObj {
    int* m_vtable;

    void SetHilite(int arg);
};

void SetHiliteObj::SetHilite(int arg) {
    int masked = arg & 0x1F;
    if (masked != 0) {
        int val = m_vtable[0x84 / 4];
        if ((val & 0x1F) == 0) {
            SetHilite_Func1(this, 1);
        }
    } else {
        int val = m_vtable[0x84 / 4];
        if ((val & 0x1F) != 0) {
            SetHilite_Func1(this, 0);
        }
    }
    SetHilite_Func2(m_vtable, masked);
}
