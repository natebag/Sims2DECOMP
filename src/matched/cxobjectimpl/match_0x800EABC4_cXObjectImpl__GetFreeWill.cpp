// 0x800EABC4 cXObjectImpl::GetFreeWill (8B)

extern int s_freeWill;

struct cXObj_GFW {
    int GetFreeWill();
};

int cXObj_GFW::GetFreeWill() {
    return s_freeWill;
}
