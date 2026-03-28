/* cXObjectImpl::GetAttr(int) - 16 bytes */

class cXObjectImpl {
public:
    char pad[0x08];
    short* m_attrs;

    short GetAttr(int index);
};

short cXObjectImpl::GetAttr(int index) {
    return m_attrs[index];
}
