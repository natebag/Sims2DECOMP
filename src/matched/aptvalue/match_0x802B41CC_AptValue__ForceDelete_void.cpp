// 0x802B41CC (124B) AptValue::ForceDelete(void)
//
// Tears down the value: invokes two cleanup virtuals (slot 11 @vt+0x58, slot 12
// @vt+0x60), then, if the value pointer is non-null, the delete virtual (slot 15
// @vt+0x78) with mode 3. Polymorphic AptValueObj box (vptr@0x08, GCC 8-byte
// vtable entries -> virtual N at vt+0x08*N). The redundant `this != 0` guard is
// in the original (SN keeps it). Clean structural C++, no surgery.

struct AptValueObjHead {
    unsigned int m_flags;
    unsigned int m_field04;
};

struct AptValueObj : public AptValueObjHead {
    virtual void v1();   virtual void v2();   virtual void v3();   virtual void v4();
    virtual void v5();   virtual void v6();   virtual void v7();   virtual void v8();
    virtual void v9();   virtual void v10();
    virtual void v11();          // vt+0x58
    virtual void v12();          // vt+0x60
    virtual void v13();  virtual void v14();
    virtual void v15(int);       // vt+0x78
    void ForceDelete();
};

void AptValueObj::ForceDelete() {
    v11();
    v12();
    if (this != 0)
        v15(3);
}
