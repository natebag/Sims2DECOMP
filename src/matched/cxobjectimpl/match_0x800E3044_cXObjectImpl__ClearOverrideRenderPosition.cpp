// 0x800E3044 cXObjectImpl::ClearOverrideRenderPosition (12B)

struct cXObj_ClearOverrideRenderPosition {
    char pad[0xCC];
    int m_val;
    void ClearOverrideRenderPosition();
};

void cXObj_ClearOverrideRenderPosition::ClearOverrideRenderPosition() {
    m_val = 0;
}
