// FLAGS: -msdata=eabi -G 8
// 0x80075150 SimsMemCardWrap::IsCardDamaged (100b)
struct CardSys {
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20();
    virtual int V21(int slot, int* out);
};

extern CardSys* g_cardSystem;

int SimsMemCardWrap_IsCardDamaged(int slot, int* outResult) {
    int local;
    if (g_cardSystem->V21(slot, &local) == -8) {
        *outResult = 1;
    } else {
        *outResult = 0;
    }
    return 1;
}
