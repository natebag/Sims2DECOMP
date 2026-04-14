// 0x800DE780 cXObjectImpl::GetSpriteSlot (8B)

struct cXObj_GetSpriteSlot {
    char pad[0xB0];
    int m_val;
    int GetSpriteSlot();
};

int cXObj_GetSpriteSlot::GetSpriteSlot() {
    return m_val;
}
