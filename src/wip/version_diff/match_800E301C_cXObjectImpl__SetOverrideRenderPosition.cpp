/* cXObjectImpl::SetOverrideRenderPosition(float, float) - 20 bytes */

class cXObjectImpl {
public:
    char pad[0xCC];
    int m_hasOverrideRenderPos;
    float m_overrideRenderX;
    float m_overrideRenderY;

    void SetOverrideRenderPosition(float x, float y);
};

void cXObjectImpl::SetOverrideRenderPosition(float x, float y) {
    m_overrideRenderX = x;
    m_overrideRenderY = y;
    m_hasOverrideRenderPos = 1;
}
