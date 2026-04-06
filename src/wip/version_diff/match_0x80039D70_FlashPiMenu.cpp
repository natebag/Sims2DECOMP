// 0x80039D70 FlashPiMenu::FlashPiMenu (36b)

struct FlashPiMenu_vtable {
    void* methods[4];
};

// Vtable at 0x8046B680
extern FlashPiMenu_vtable g_FlashPiMenu_vtable;

class FlashPiMenu {
public:
    int field0;                   // offset 0
    int field4;                   // offset 4
    int field8;                   // offset 8
    FlashPiMenu_vtable* vtable;   // offset 0x0C = 12
};

void FlashPiMenu_ctor(FlashPiMenu* this_, int param) {
    this_->vtable = &g_FlashPiMenu_vtable;
    this_->field8 = param;
    this_->field4 = 0;
    this_->field0 = 0;
}

extern "C" void _ZN11FlashPiMenuC1Ei(FlashPiMenu* this_, int param) {
    FlashPiMenu_ctor(this_, param);
}
