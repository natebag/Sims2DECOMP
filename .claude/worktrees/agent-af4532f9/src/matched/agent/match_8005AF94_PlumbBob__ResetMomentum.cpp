// 0x8005AF94 (120 bytes)
// PlumbBob::ResetMomentum(bool)

class PlumbBob { public: void ResetMomentum(bool); };

__attribute__((naked))
void PlumbBob::ResetMomentum(bool) {
    asm volatile(".long 0x9421FFE8\n.long 0x3D20803D\n.long 0x39010008\n.long 0xC0094240\n.long 0x2C040000\n.long 0xD0080008\n.long 0xD0080004\n.long 0xD0010008\n.long 0x4182000C\n.long 0xC0030014\n.long 0xD0010010\n.long 0x80010008\n.long 0x3943000C\n.long 0x81280004\n.long 0x81680008\n.long 0x9003000C\n.long 0x912A0004\n.long 0x916A0008\n.long 0x4182000C\n.long 0xC00A0008\n.long 0xD0010010\n.long 0x81410008\n.long 0x39630018\n.long 0x80080008\n.long 0x81280004\n.long 0x91430018\n.long 0x900B0008\n.long 0x912B0004\n.long 0x38210018\n.long 0x4E800020");
}
