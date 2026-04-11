// ScrollingTextBox::SetPosition(EVec2 &, EVec2 &)
// Address: 0x8006CA38 | Size: 36 bytes
// Pattern: Simple field copying from two EVec2 references
// Note: EVec2 has y before x in original layout

struct EVec2 {
    float y;  // 0x00 - y comes first!
    float x;  // 0x04
};

struct ScrollingTextBox {
    char pad[4];
    EVec2 m_position;    // 0x04
    EVec2 m_size;        // 0x0C
};

extern "C" void ScrollingTextBox_SetPosition(ScrollingTextBox* this_, EVec2* pos, EVec2* size) {
    this_->m_position = *pos;
    this_->m_size = *size;
}
