// 0x801164B0 cHitMan::GetSourceDataField (52b)

struct cHitMan {
    char pad[0x30];
    void* vtable;  // at offset 0x30 for blrl dispatch

    int GetSourceDataField(int, int, int*);
};

// Virtual interface for dispatch
struct IVTable {
    virtual int V0();
    virtual int V1();
    virtual int V2();
    virtual int V3();
    virtual int V4();
    virtual int V5();
    virtual int V6();
    virtual int V7();
    virtual int V8();
    virtual int V9();
    virtual int GetSourceDataField(int, int, int*);  // V10
};

int cHitMan::GetSourceDataField(int a, int b, int* c) {
    return ((IVTable*)this)->GetSourceDataField(a, b, c);
}
