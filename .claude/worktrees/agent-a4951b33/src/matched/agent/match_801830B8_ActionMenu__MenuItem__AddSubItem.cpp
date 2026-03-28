// 0x801830B8 (104 bytes)
// ActionMenu::MenuItem::AddSubItem(ActionMenu::MenuItem *)

class ActionMenu { public: void MenuItem::AddSubItem(ActionMenu::MenuItem *); };

__attribute__((naked))
void ActionMenu::MenuItem::AddSubItem(ActionMenu::MenuItem *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C691B78\n.long 0x7C9E2378\n.long 0x8069005C\n.long 0x2C030000\n.long 0x40820014\n.long 0x93C9005C\n.long 0x4800002C\n.long 0x7FE3FB78\n.long 0x48000161\n.long 0x7C7F1B78\n.long 0x7FE3FB78\n.long 0x4800015D\n.long 0x2C030000\n.long 0x4082FFE8\n.long 0x7FE3FB78\n.long 0x7FC4F378\n.long 0x4BFFFFA1\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
