/* cXObjectImpl::GetNumAttr(void) - 8 bytes */

class cXObjectImpl {
public:
    char pad[0x0C];
    int m_numAttr;

    int GetNumAttr(void);
};

int cXObjectImpl::GetNumAttr(void) {
    return m_numAttr;
}
