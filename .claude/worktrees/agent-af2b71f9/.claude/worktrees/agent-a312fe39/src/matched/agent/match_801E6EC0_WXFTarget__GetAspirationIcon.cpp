// 0x801E6EC0 (72 bytes)
// WXFTarget::GetAspirationIcon(void)

class WXFTarget { public: void GetAspirationIcon(void); };

__attribute__((naked))
void WXFTarget::GetAspirationIcon(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80830094\n.long 0x3C608047\n.long 0x38635DCC\n.long 0x4BE598C5\n.long 0x81230004\n.long 0x38800014\n.long 0xA8090138\n.long 0x8129013C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
