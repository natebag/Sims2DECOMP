
void RbTreeInsertEqual_ParentCtor(void *, int);

extern void* __vt__RbTreeInsertEqual[];

struct RbTreeInsertEqual {
    void* m_vtable;
    RbTreeInsertEqual(void);
};

RbTreeInsertEqual::RbTreeInsertEqual(void) {
    RbTreeInsertEqual_ParentCtor(this, 3);
    m_vtable = __vt__RbTreeInsertEqual;
}
