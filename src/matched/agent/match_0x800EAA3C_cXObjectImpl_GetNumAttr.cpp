// 0x800EAA3C (8B) cXObjectImpl::GetNumAttr(void)
// Getter for field at offset 0xC.

class cXObjectImpl {
public:
    char pad_000[0xC];
    int m_field_C;
    int GetNumAttr(void);
};

int cXObjectImpl::GetNumAttr(void) {
    return m_field_C;
}
