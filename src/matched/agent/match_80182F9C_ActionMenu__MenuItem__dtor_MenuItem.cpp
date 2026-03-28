// 0x80182F9C (88 bytes)
// ActionMenu::MenuItem::~MenuItem(void)

class ActionMenu { public: void MenuItem::~MenuItem(void); };

__attribute__((naked))
void ActionMenu::MenuItem::~MenuItem(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x48000205\n.long 0x387F0048\n.long 0x38800002\n.long 0x4BF1EDB1\n.long 0x387F0004\n.long 0x38800002\n.long 0x4BF3E751\n.long 0x73C00001\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4814E245\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
