// 0x800EABE4 cXObjectImpl::SetAutoReset (8B)

extern int s_autoReset;

struct cXObj_SetAutoReset {
    void SetAutoReset(int v);
};

void cXObj_SetAutoReset::SetAutoReset(int v) { s_autoReset = v; }
