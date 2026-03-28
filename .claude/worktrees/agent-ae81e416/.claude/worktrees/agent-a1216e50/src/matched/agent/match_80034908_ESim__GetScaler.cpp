// 0x80034908 (68 bytes)
// ESim::GetScaler(void)

class ESim { public: void GetScaler(void); };

__attribute__((naked))
void ESim::GetScaler(void) {
    asm volatile(".long 0x8123063C\n.long 0x39290068\n.long 0x81690008\n.long 0x2C0B0000\n.long 0x41820010\n.long 0x812B0120\n.long 0xC0290088\n.long 0x4E800020\n.long 0x8129000C\n.long 0x2C090000\n.long 0x40820010\n.long 0x3D20803D\n.long 0xC029120C\n.long 0x4E800020\n.long 0x81290120\n.long 0xC0290088\n.long 0x4E800020");
}
