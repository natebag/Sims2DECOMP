// 0x800B6D20 FloatConstants::DestroyInstance (64B)

struct FloatConstants {
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
    virtual ~FloatConstants();
    static void DestroyInstance(FloatConstants *p);
};

void FloatConstants::DestroyInstance(FloatConstants *p) {
    if (p) {
        delete p;
    }
}
