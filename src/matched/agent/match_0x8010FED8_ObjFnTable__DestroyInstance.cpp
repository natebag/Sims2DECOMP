// 0x8010FED8 ObjFnTable::DestroyInstance(ObjFnTable*) (64B)

struct ObjFnTable {
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
    virtual ~ObjFnTable();
    static void DestroyInstance(ObjFnTable* p);
};

void ObjFnTable::DestroyInstance(ObjFnTable* p) {
    if (p) {
        delete p;
    }
}
