// 0x8002C274 (76 bytes)
// EIWallPart::GetWallpaperShader(void)

class EIWallPart { public: void GetWallpaperShader(void); };

__attribute__((naked))
void EIWallPart::GetWallpaperShader(void) {
    asm volatile(".long 0x7C691B78\n.long 0x806903A0\n.long 0x2C030000\n.long 0x4C820020\n.long 0x80690120\n.long 0x2C030000\n.long 0x41820020\n.long 0x80030040\n.long 0x2C000000\n.long 0x41820014\n.long 0x8063003C\n.long 0x80030004\n.long 0x2C000000\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x81230000\n.long 0x80690008\n.long 0x4E800020");
}
