// 0x800E0F34 cXObjectImpl::ReconType (12B) — returns 'XOBJ' magic

struct cXObj_RT {
    int ReconType();
};

int cXObj_RT::ReconType() {
    return 0x584F424A;
}
