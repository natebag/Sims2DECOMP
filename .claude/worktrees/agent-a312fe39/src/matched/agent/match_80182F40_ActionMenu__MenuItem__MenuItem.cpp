// 0x80182F40 (92 bytes)
// ActionMenu::MenuItem::MenuItem(void)

class ActionMenu { public: void MenuItem::MenuItem(void); };

__attribute__((naked))
void ActionMenu::MenuItem::MenuItem(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x387E0004\n.long 0x4BF3E1E9\n.long 0x387E0048\n.long 0x4BF1EB75\n.long 0x38000000\n.long 0x7FC3F378\n.long 0x901E0060\n.long 0x901E0000\n.long 0x901E004C\n.long 0x901E0050\n.long 0x901E0054\n.long 0x901E0058\n.long 0x901E005C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
