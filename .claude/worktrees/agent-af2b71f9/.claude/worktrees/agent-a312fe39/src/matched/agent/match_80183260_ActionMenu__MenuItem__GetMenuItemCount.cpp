// 0x80183260 (72 bytes)
// ActionMenu::MenuItem::GetMenuItemCount(void) const

class ActionMenu { public: void MenuItem::GetMenuItemCount(void) const; };

__attribute__((naked))
void ActionMenu::MenuItem::GetMenuItemCount(void) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x4BFFFFE1\n.long 0x3BE00001\n.long 0x7C631B79\n.long 0x41820014\n.long 0x4BFFFFD1\n.long 0x3BFF0001\n.long 0x7C631B79\n.long 0x4082FFF4\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
