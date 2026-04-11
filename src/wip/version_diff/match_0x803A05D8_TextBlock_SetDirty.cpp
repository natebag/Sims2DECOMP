// TextBlock::SetDirty(void)
// Address: 0x803A05D8 | Size: 16 bytes
// DOL: lwz r0,56(r3); oris r0,r0,0x1000; stw r0,56(r3); blr
// oris is upper-halfword OR, so the constant in C is 0x10000000

struct TextBlock {
    char pad[56];
    unsigned int m_flags;  // at offset 56
};

extern "C" void TextBlock_SetDirty(TextBlock* this_) {
    this_->m_flags |= 0x10000000u;
}
