// FLAGS: -fno-schedule-insns
// 0x80039D70 FlashPiMenu::FlashPiMenu (36b)

struct FlashPiMenu_vtable {
    void* methods[4];
};

// Vtable at 0x8046B680
extern FlashPiMenu_vtable g_FlashPiMenu_vtable;

struct FlashPiMenu {
    int field0;                   // offset 0
    int field4;                   // offset 4
    int field8;                   // offset 8
    FlashPiMenu_vtable* vtable;   // offset 0x0C = 12
};

void FlashPiMenu_C1(FlashPiMenu* this_, int param) {
    FlashPiMenu_vtable* vt = &g_FlashPiMenu_vtable;
    int zero = 0;
    register FlashPiMenu* self asm("r11");
    self = this_;
    
    self->vtable = vt;
    self->field8 = param;
    self->field4 = zero;
    self->field0 = zero;
}
