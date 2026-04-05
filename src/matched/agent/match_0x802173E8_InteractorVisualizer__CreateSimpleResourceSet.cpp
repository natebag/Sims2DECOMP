void *CSRS_Check(void);
void *CSRS_Create(void *, void *, int);

struct CSRS_S {
    void *CreateSimpleResourceSet(void *interactor, int flags);
};

void *CSRS_S::CreateSimpleResourceSet(void *interactor, int flags) {
    if (CSRS_Check() == 0) {
        return 0;
    }
    return CSRS_Create(this, interactor, flags);
}
