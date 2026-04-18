// 0x801EE200 (100B) INVTarget::SetPlayerFunds(int) — MI-vcall at slot 26

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
    virtual void SetFunds(int mode, int zero) = 0;
};

extern CashProvider* g_CashProvider;

struct INVTarget {
    char pad[0x84];
    int m_mode_flag;
    int SetPlayerFunds(int amount);
};

int INVTarget::SetPlayerFunds(int /*amount*/) {
    CashProvider* p = g_CashProvider;
    if (p == 0) return 0;
    int mode = (m_mode_flag != 0) ? 1 : 0;
    p->SetFunds(mode, 0);
    return 1;
}
