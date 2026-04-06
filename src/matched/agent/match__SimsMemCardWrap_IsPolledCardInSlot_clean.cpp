

struct CardSys {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual int V18(int);
};

extern CardSys* g_cardSystem;

int SimsMemCardWrap_IsPolledCardInSlot(int slot, int* result) {
    *result = g_cardSystem->V18(slot);
    return 1;
}
