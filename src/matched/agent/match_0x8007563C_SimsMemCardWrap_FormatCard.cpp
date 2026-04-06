// FLAGS: -msdata=eabi -G 8
// 0x8007563C SimsMemCardWrap::FormatCard (60b)
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
    virtual int V12(int);
};

extern CardSys* g_cardSystem;

int SimsMemCardWrap_FormatCard(int param) {
    return g_cardSystem->V12(param);
}
