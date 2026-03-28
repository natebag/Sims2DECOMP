/* cXObjectImpl::ClearOverrideRenderPosition(void) - 12 bytes */

class cXObjectImpl {
public:
    char pad[0xCC];
    int m_overrideRenderPosition;

    void ClearOverrideRenderPosition(void);
};

void cXObjectImpl::ClearOverrideRenderPosition(void) {
    m_overrideRenderPosition = 0;
}
