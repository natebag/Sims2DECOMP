// FLAGS: -fno-schedule-insns
// 0x8004AFA8 (68 bytes)
// BBI::InventoryItems::GetNewItemIndex(void) const

struct InventoryItems_GNI {
    void* m_slots[36];
    int GetNewItemIndex() const;
};

int InventoryItems_GNI::GetNewItemIndex() const {
    int index = 0;
    int result = -1;
    if (!m_slots[index]) {
        result = index;
        goto done;
    }
loop_inc:
    index++;
    if (index > 35) goto done;
    if (m_slots[index]) goto loop_inc;
    result = index;
done:
    return result;
}
