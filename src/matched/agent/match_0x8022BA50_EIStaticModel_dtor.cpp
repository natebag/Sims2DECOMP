
extern void* __vt__EIStaticModel[];

void EIStaticModel_DtorBody(void *);
void EIStaticModel_Cleanup(void *, int);
void* EIStaticModel_GetAllocator(void);
void EIStaticModel_Free(void *, void *);

struct EIStaticModel {
    void* m_vtable;

    void dtor(int flags);
};

void EIStaticModel::dtor(int flags) {
    m_vtable = __vt__EIStaticModel;
    EIStaticModel_DtorBody(this);
    EIStaticModel_Cleanup(this, 0);
    if (flags & 1) {
        EIStaticModel_Free(EIStaticModel_GetAllocator(), this);
    }
}
