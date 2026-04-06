

struct CardSys {
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual int V24(int, int, int);
};

extern CardSys* g_cardSystem;
extern int g_saveSlot;

int SimsMemCardWrap_HasSavedGame(int p1, int p2) {
    return g_cardSystem->V24(g_saveSlot, p1, p2);
}
