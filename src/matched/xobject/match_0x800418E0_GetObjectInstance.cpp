// 0x800418E0 GetObjectInstance(cXObject*) (72B)

class Inner {
public:
    char pad_00[24];
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void* GetInstance();
};

class cXObject {
public:
    Inner* m_inner;
};

void* GetObjectInstance(cXObject* obj) {
    void* r;
    if (obj != 0) {
        return obj->m_inner->GetInstance();
    }
    r = 0;
    return r;
}
