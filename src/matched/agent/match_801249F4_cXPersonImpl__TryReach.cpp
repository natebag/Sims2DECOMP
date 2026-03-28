// 0x801249F4 (88 bytes)
// cXPersonImpl::TryReach(StackElem *, XPrimParam *)

class cXPersonImpl { public: void TryReach(StackElem *, XPrimParam *); };

__attribute__((naked))
void cXPersonImpl::TryReach(StackElem *, XPrimParam *) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0x93E1001C\n.long 0x90010024\n.long 0x7CBF2B78\n.long 0x38C10008\n.long 0x38E1000C\n.long 0x39010010\n.long 0x39210014\n.long 0x4BFFFD85\n.long 0x7C602379\n.long 0x41820018\n.long 0xA81F0002\n.long 0x21200000\n.long 0x7C090114\n.long 0x7C040378\n.long 0x38600000\n.long 0x80010024\n.long 0x7C0803A6\n.long 0x83E1001C\n.long 0x38210020\n.long 0x4E800020");
}
