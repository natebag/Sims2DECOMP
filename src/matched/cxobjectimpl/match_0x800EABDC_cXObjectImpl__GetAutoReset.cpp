// 0x800EABDC cXObjectImpl::GetAutoReset (8B)

extern int s_autoReset;

struct cXObj_GetAutoReset {
    int GetAutoReset();
};

int cXObj_GetAutoReset::GetAutoReset() { return s_autoReset; }
