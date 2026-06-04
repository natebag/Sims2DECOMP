// 0x802B31F4 (84B) AptValueShutdownRemaining(void)
//
// Shutdown hook: dispatches the slot-3 cleanup virtual (vt+0x18) on the two
// global APT value managers/pools. Clean structural C++, default scheduling.

struct AptValueObjHead {
    unsigned int m_flags;
    unsigned int m_field04;
};

struct AptValueObj : public AptValueObjHead {
    virtual void v1();
    virtual void v2();
    virtual void v3();   // vt+0x18
};

extern AptValueObj* g_aptObjA;   // -22936(r13)
extern AptValueObj* g_aptObjB;   // -22916(r13)

void AptValueShutdownRemaining() {
    g_aptObjA->v3();
    g_aptObjB->v3();
}
