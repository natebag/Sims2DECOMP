// 0x80142FC0 (112 bytes)
// SpriteSlot::SetSprite(unsigned int, int, int, bool)

class SpriteSlot { public: void SetSprite(unsigned int, int, int, bool); };

__attribute__((naked))
void SpriteSlot::SetSprite(unsigned int, int, int, bool) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7CE73B79\n.long 0x90BF0018\n.long 0x90DF002C\n.long 0x41820018\n.long 0x3806FFFF\n.long 0x3920FFFF\n.long 0x901F0030\n.long 0x913F0034\n.long 0x48000010\n.long 0x38000001\n.long 0x90FF0030\n.long 0x901F0034\n.long 0x806DAC48\n.long 0x7FE4FB78\n.long 0x4BEFE6D9\n.long 0x3800FFFF\n.long 0x901F0040\n.long 0x901F003C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
