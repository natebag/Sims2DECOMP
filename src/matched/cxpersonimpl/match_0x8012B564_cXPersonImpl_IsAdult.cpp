// 0x8012B564 cXPersonImpl::IsAdult(void) (60B) — MI vcall at vt[336/340], always returns 1

struct SubNonVirtual { int pad0; };

struct SubBase : public SubNonVirtual {
    virtual void f1() = 0; virtual void f2() = 0; virtual void f3() = 0;
    virtual void f4() = 0; virtual void f5() = 0; virtual void f6() = 0;
    virtual void f7() = 0; virtual void f8() = 0; virtual void f9() = 0;
    virtual void f10() = 0; virtual void f11() = 0; virtual void f12() = 0;
    virtual void f13() = 0; virtual void f14() = 0; virtual void f15() = 0;
    virtual void f16() = 0; virtual void f17() = 0; virtual void f18() = 0;
    virtual void f19() = 0; virtual void f20() = 0; virtual void f21() = 0;
    virtual void f22() = 0; virtual void f23() = 0; virtual void f24() = 0;
    virtual void f25() = 0; virtual void f26() = 0; virtual void f27() = 0;
    virtual void f28() = 0; virtual void f29() = 0; virtual void f30() = 0;
    virtual void f31() = 0; virtual void f32() = 0; virtual void f33() = 0;
    virtual void f34() = 0; virtual void f35() = 0; virtual void f36() = 0;
    virtual void f37() = 0; virtual void f38() = 0; virtual void f39() = 0;
    virtual void f40() = 0; virtual void f41() = 0;
    virtual void VcallAt42() = 0;  // slot 42, offset 336 — discarded
};

struct cXPersonImpl {
    char pad[4];
    SubBase* m_sub;
    int IsAdult();
};

int cXPersonImpl::IsAdult() {
    m_sub->VcallAt42();
    return 1;
}
