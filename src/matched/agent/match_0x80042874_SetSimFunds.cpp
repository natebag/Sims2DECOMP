// 0x80042874 (92B) SetSimFunds(unsigned int, int) — MI-vcall at slot 26 on g_CashProvider

class CashProvider {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void SetFunds(int value, int mode) = 0;
};

extern CashProvider* g_CashProvider;

int SetSimFunds(unsigned int flag, int value) {
    CashProvider* p = g_CashProvider;
    if (p == 0) return 0;
    int mode = (flag != 0) ? 1 : 0;
    p->SetFunds(value, mode);
    return 1;
}
