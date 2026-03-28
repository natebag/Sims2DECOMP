// 0x800D2700 (68 bytes)
// NghLayout::GetSectionNumberForOffset(unsigned int)

class NghLayout { public: void GetSectionNumberForOffset(unsigned int); };

__attribute__((naked))
void NghLayout::GetSectionNumberForOffset(unsigned int) {
    asm volatile(".long 0x81230004\n.long 0x38600000\n.long 0x80090004\n.long 0x2C000000\n.long 0x4C810020\n.long 0x8009000C\n.long 0x7C802051\n.long 0x4D800020\n.long 0x39290018\n.long 0x38630001\n.long 0x80090004\n.long 0x2C000000\n.long 0x4C810020\n.long 0x8009000C\n.long 0x7C802051\n.long 0x4080FFE4\n.long 0x4E800020");
}
