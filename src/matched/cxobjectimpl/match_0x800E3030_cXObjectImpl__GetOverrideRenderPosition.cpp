// 0x800E3030 cXObjectImpl::GetOverrideRenderPosition (20B)

struct cXObj_GORP {
    char pad[0xD0];
    float m_x;
    float m_y;
    void GetOverrideRenderPosition(float& a, float& b);
};

void cXObj_GORP::GetOverrideRenderPosition(float& a, float& b) {
    a = m_x;
    b = m_y;
}
