// 0x80132224 cXPortalImpl::PostLoad(int, bool) (72B)

class cXMTObjectImpl {
public:
    void PostLoad(int a, bool b);
};

class cXPortalImpl {
public:
    cXMTObjectImpl* m_obj;
    void PostLoad(int reasonCode, bool flag);
    void ApplyWallStyle(bool b);
};

void cXPortalImpl::PostLoad(int reasonCode, bool flag) {
    m_obj->PostLoad(reasonCode, flag);
    if (reasonCode <= 51) {
        ApplyWallStyle(true);
    }
}
