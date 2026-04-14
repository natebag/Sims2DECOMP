// 0x800EABCC cXObjectImpl::GetAutoCenter (8B)

extern int s_autoCenter;

struct cXObj_GetAutoCenter {
    int GetAutoCenter();
};

int cXObj_GetAutoCenter::GetAutoCenter() { return s_autoCenter; }
