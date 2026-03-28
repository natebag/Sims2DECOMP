/* cXObjectImpl::SetAttr(int, short) - 16 bytes */

class cXObjectImpl {
public:
    char pad[0x08];
    short* m_attrs;

    void SetAttr(int index, short value);
};

void cXObjectImpl::SetAttr(int index, short value) {
    m_attrs[index] = value;
}
