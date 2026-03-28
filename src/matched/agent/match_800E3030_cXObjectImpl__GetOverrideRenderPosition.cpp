/* cXObjectImpl::GetOverrideRenderPosition(float &, float &) - 20 bytes */

class cXObjectImpl {
public:
    char pad[0xCC];
    int m_hasOverrideRenderPosition;
    float m_overrideRenderX;
    float m_overrideRenderY;

    void GetOverrideRenderPosition(float& x, float& y);
};

void cXObjectImpl::GetOverrideRenderPosition(float& x, float& y) {
    x = m_overrideRenderX;
    y = m_overrideRenderY;
}
