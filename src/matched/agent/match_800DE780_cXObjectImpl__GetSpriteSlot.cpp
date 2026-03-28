/* cXObjectImpl::GetSpriteSlot(void) - 0x800DE780 (8 bytes) */

struct cXObjectImpl {
    char m_pad[0xB0];
    int m_spriteSlot;

    int GetSpriteSlot(void);
};

int cXObjectImpl::GetSpriteSlot(void) {
    return m_spriteSlot;
}
