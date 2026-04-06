// PaneItem::Reset(void)
// Address: 0x803A07BC | Size: 12 bytes
// Pattern: Stores 1 to field at offset 4

struct PaneItem {
    int m_field0;
    int m_flag;  // at offset 4
};

extern "C" void PaneItem_Reset(PaneItem* this_) {
    this_->m_flag = 1;
}
