// 0x800BCB04 (100 bytes)
// IconGroupImpl::GetSpriteID(int)

class IconGroupImpl { public: void GetSpriteID(int); };

__attribute__((naked))
void IconGroupImpl::GetSpriteID(int) {
    asm volatile(".long 0x7C691B78\n.long 0x8069000C\n.long 0x2C030000\n.long 0x41820020\n.long 0xA0630004\n.long 0x7C600734\n.long 0x2C00FFFF\n.long 0x41820010\n.long 0x7C632214\n.long 0x7C630734\n.long 0x4E800020\n.long 0x80090004\n.long 0x2C000000\n.long 0x40820028\n.long 0x2C040000\n.long 0x41800020\n.long 0x2C040012\n.long 0x41810018\n.long 0x3D20803E\n.long 0x7C042214\n.long 0x39299E3E\n.long 0x7C6902AE\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
