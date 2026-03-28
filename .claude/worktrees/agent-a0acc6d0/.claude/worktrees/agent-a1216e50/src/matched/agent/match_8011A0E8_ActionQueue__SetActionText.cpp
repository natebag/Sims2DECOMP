// 0x8011A0E8 (104 bytes)
// ActionQueue::SetActionText(BString2 &, unsigned int)

class ActionQueue { public: void SetActionText(BString2 &, unsigned int); };

__attribute__((naked))
void ActionQueue::SetActionText(BString2 &, unsigned int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C691B78\n.long 0x806902A8\n.long 0x800902AC\n.long 0x7C030050\n.long 0x7C050040\n.long 0x40800034\n.long 0x3C00CCCC\n.long 0x7C632A14\n.long 0x6000CCCD\n.long 0x7C030016\n.long 0x5400E8FE\n.long 0x1C00000A\n.long 0x7C601850\n.long 0x1C630044\n.long 0x7C691A14\n.long 0x4BFA7831\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
