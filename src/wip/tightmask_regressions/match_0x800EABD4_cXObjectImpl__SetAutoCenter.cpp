// 0x800EABD4 cXObjectImpl::SetAutoCenter (8B)

extern int s_autoCenter;

struct cXObj_SetAutoCenter {
    void SetAutoCenter(int v);
};

void cXObj_SetAutoCenter::SetAutoCenter(int v) { s_autoCenter = v; }
