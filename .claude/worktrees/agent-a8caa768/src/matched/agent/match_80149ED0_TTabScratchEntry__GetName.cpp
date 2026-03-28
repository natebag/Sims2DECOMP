// 0x80149ED0 (76 bytes)
// TTabScratchEntry::GetName(void) const

class TTabScratchEntry { public: void GetName(void) const; };

__attribute__((naked))
void TTabScratchEntry::GetName(void) const {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x800DA268\n.long 0x2C000000\n.long 0x40820020\n.long 0x386DA264\n.long 0x4BF57BE9\n.long 0x38000001\n.long 0x3C608015\n.long 0x900DA268\n.long 0x386392C4\n.long 0x480F8901\n.long 0x386DA264\n.long 0x4BF5946D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
