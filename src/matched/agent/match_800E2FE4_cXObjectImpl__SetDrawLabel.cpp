/* cXObjectImpl::SetDrawLabel(bool) - 20 bytes */

class cXObjectImpl {
public:
    char pad[0xC4];
    int m_drawLabel;

    void SetDrawLabel(int val);
};

void cXObjectImpl::SetDrawLabel(int val) {
    if (m_drawLabel == val) return;
    m_drawLabel = val;
}
