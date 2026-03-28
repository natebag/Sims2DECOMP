/* cXObjectImpl::OverrideRenderPosition(float &, float &) - 36 bytes */

class cXObjectImpl {
public:
    char pad[0xCC];
    int m_hasOverrideRenderPosition;
    float m_overrideRenderX;
    float m_overrideRenderY;

    int OverrideRenderPosition(float& x, float& y);
};

int cXObjectImpl::OverrideRenderPosition(float& x, float& y) {
    if (m_hasOverrideRenderPosition != 0) {
        x = m_overrideRenderX;
        y = m_overrideRenderY;
    }
    return m_hasOverrideRenderPosition;
}
