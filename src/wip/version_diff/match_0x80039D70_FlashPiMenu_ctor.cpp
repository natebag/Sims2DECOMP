// FlashPiMenu::FlashPiMenu(int)
// Address: 0x80039D70 | Size: 36 bytes
// VERSION_DIFF: Uses r11 for this pointer, compiler uses r3

struct FlashPiMenu {
    int m_field0;      // 0x00
    int m_field4;      // 0x04
    int m_field8;      // 0x08
    void* m_vtable;    // 0x0C - vtable pointer
};

// vtable at 0x8046B680
extern char gFlashPiMenuVtable[4];

extern "C" void* FlashPiMenu_ctor(FlashPiMenu* this_, int arg) {
    this_->m_field0 = 0;
    this_->m_field4 = 0;
    this_->m_field8 = arg;
    this_->m_vtable = &gFlashPiMenuVtable;
    return this_;
}
