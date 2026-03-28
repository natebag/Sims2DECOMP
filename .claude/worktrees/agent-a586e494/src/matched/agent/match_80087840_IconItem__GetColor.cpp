// 0x80087840 (100 bytes)
// IconItem::GetColor(void)

class IconItem { public: void GetColor(void); };

__attribute__((naked))
void IconItem::GetColor(void) {
    asm volatile(".long 0x9421FFE8\n.long 0xC0040020\n.long 0x39040020\n.long 0xC164002C\n.long 0x3D40803D\n.long 0xD0010008\n.long 0x39210008\n.long 0xC18A7320\n.long 0x7C6B1B78\n.long 0xC0080004\n.long 0xD0090004\n.long 0xC1A80008\n.long 0xD189000C\n.long 0xD1A90008\n.long 0xD1610014\n.long 0xC1810008\n.long 0xC169000C\n.long 0xC0090004\n.long 0xC1A90008\n.long 0xD18B0000\n.long 0xD00B0004\n.long 0xD1AB0008\n.long 0xD16B000C\n.long 0x38210018\n.long 0x4E800020");
}
