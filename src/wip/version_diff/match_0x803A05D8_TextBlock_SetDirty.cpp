// TextBlock::SetDirty(void)
// Address: 0x803A05D8 | Size: 16 bytes
// Pattern: ORs 0x1000 (using oris) into field at offset 56

struct TextBlock {
    char pad[56];
    unsigned int m_flags;  // at offset 56
};

extern "C" void TextBlock_SetDirty(TextBlock* this_) {
    // Use 1 << 12 to generate oris instruction
    this_->m_flags |= (1 << 12);
}
