void *BS_StaticInit(void);
void *BS_AllocDefault(void *, int, int);
void *BS_InitCap(void *, int, int);

struct BS_CtorCap {
    void *m_data;
    BS_CtorCap *ctor(int capacity, int flags);
};

BS_CtorCap *BS_CtorCap::ctor(int capacity, int flags) {
    void *r = BS_StaticInit();
    r = BS_AllocDefault(r, 16, 0);
    m_data = BS_InitCap(r, capacity, flags);
    return this;
}
