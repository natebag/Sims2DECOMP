// 0x800EB1D0 cXObjectImpl::IsRoof (72B) — MI vcall vt[784/788] returns obj, short@18 == 14

struct TileInfo {
    char pad[18];
    short m_kind;  // +18
};

struct SubNonVirtual { int pad0; };

struct SubBase : public SubNonVirtual {
    virtual void f01() = 0; virtual void f02() = 0; virtual void f03() = 0; virtual void f04() = 0; virtual void f05() = 0;
    virtual void f06() = 0; virtual void f07() = 0; virtual void f08() = 0; virtual void f09() = 0; virtual void f10() = 0;
    virtual void f11() = 0; virtual void f12() = 0; virtual void f13() = 0; virtual void f14() = 0; virtual void f15() = 0;
    virtual void f16() = 0; virtual void f17() = 0; virtual void f18() = 0; virtual void f19() = 0; virtual void f20() = 0;
    virtual void f21() = 0; virtual void f22() = 0; virtual void f23() = 0; virtual void f24() = 0; virtual void f25() = 0;
    virtual void f26() = 0; virtual void f27() = 0; virtual void f28() = 0; virtual void f29() = 0; virtual void f30() = 0;
    virtual void f31() = 0; virtual void f32() = 0; virtual void f33() = 0; virtual void f34() = 0; virtual void f35() = 0;
    virtual void f36() = 0; virtual void f37() = 0; virtual void f38() = 0; virtual void f39() = 0; virtual void f40() = 0;
    virtual void f41() = 0; virtual void f42() = 0; virtual void f43() = 0; virtual void f44() = 0; virtual void f45() = 0;
    virtual void f46() = 0; virtual void f47() = 0; virtual void f48() = 0; virtual void f49() = 0; virtual void f50() = 0;
    virtual void f51() = 0; virtual void f52() = 0; virtual void f53() = 0; virtual void f54() = 0; virtual void f55() = 0;
    virtual void f56() = 0; virtual void f57() = 0; virtual void f58() = 0; virtual void f59() = 0; virtual void f60() = 0;
    virtual void f61() = 0; virtual void f62() = 0; virtual void f63() = 0; virtual void f64() = 0; virtual void f65() = 0;
    virtual void f66() = 0; virtual void f67() = 0; virtual void f68() = 0; virtual void f69() = 0; virtual void f70() = 0;
    virtual void f71() = 0; virtual void f72() = 0; virtual void f73() = 0; virtual void f74() = 0; virtual void f75() = 0;
    virtual void f76() = 0; virtual void f77() = 0; virtual void f78() = 0; virtual void f79() = 0; virtual void f80() = 0;
    virtual void f81() = 0; virtual void f82() = 0; virtual void f83() = 0; virtual void f84() = 0; virtual void f85() = 0;
    virtual void f86() = 0; virtual void f87() = 0; virtual void f88() = 0; virtual void f89() = 0; virtual void f90() = 0;
    virtual void f91() = 0; virtual void f92() = 0; virtual void f93() = 0; virtual void f94() = 0; virtual void f95() = 0;
    virtual void f96() = 0; virtual void f97() = 0;
    virtual TileInfo* VcallAt98() = 0;  // slot 98, offset 784
};

struct cXObjectImpl {
    char pad[4];
    SubBase* m_sub;
    int IsRoof();
};

int cXObjectImpl::IsRoof() {
    TileInfo* t = m_sub->VcallAt98();
    return t->m_kind == 14;
}
