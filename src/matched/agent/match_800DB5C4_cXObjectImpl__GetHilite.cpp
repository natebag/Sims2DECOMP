/* cXObjectImpl::GetHilite(void) - 0x800DB5C4 (12 bytes) */

struct cXObjectImpl {
    char m_pad[0x84];
    int m_hiliteFlags;

    int GetHilite(void);
};

int cXObjectImpl::GetHilite(void) {
    return m_hiliteFlags & 0x1F;
}
