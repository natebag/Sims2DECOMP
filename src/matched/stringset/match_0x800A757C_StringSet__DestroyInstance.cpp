// 0x800A757C StringSet::DestroyInstance (64B)

struct StringSet {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual ~StringSet();
    static void DestroyInstance(StringSet *p);
};

void StringSet::DestroyInstance(StringSet *p) {
    if (p) {
        delete p;
    }
}
