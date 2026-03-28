// 0x801843A8 (84 bytes)
// ActionMenu::CloseMenu(void)

class ActionMenu { public: void CloseMenu(void); };

__attribute__((naked))
void ActionMenu::CloseMenu(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C691B78\n.long 0x88090009\n.long 0x2C000004\n.long 0x4182001C\n.long 0x2C000002\n.long 0x41820014\n.long 0x2C000005\n.long 0x4182000C\n.long 0x2C000006\n.long 0x40820014\n.long 0x38000009\n.long 0x7D234B78\n.long 0x98090009\n.long 0x48000015\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
