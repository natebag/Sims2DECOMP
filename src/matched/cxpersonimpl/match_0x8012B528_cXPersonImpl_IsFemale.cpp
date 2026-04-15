// 0x8012B528 cXPersonImpl::IsFemale(void) (60B) — MI vcall at vt[512/516], XOR 1

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
    virtual void f40() = 0; virtual void f41() = 0; virtual void f42() = 0;
    virtual void f43() = 0; virtual void f44() = 0; virtual void f45() = 0;
    virtual void f46() = 0; virtual void f47() = 0; virtual void f48() = 0;
    virtual void f49() = 0; virtual void f50() = 0; virtual void f51() = 0;
    virtual void f52() = 0; virtual void f53() = 0; virtual void f54() = 0;
    virtual void f55() = 0; virtual void f56() = 0; virtual void f57() = 0;
    virtual void f58() = 0; virtual void f59() = 0; virtual void f60() = 0;
    virtual void f61() = 0; virtual void f62() = 0; virtual void f63() = 0;
    virtual int VcallAt64() = 0;  // slot 64, offset 512
};

struct cXPersonImpl {
    char pad[4];
    SubBase* m_sub;
    int IsFemale();
};

int cXPersonImpl::IsFemale() {
    return m_sub->VcallAt64() ^ 1;
}
