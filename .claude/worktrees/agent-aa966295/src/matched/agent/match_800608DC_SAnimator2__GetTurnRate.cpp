// 0x800608DC (76 bytes)
// SAnimator2::GetTurnRate(void)

class SAnimator2 { public: void GetTurnRate(void); };

__attribute__((naked))
void SAnimator2::GetTurnRate(void) {
    asm volatile(".long 0x80030018\n.long 0x3D20803D\n.long 0xC0294784\n.long 0x2C000003\n.long 0x4D820020\n.long 0x880305F8\n.long 0x2C000002\n.long 0x4D820020\n.long 0x8123002C\n.long 0x2C09000C\n.long 0x40820010\n.long 0x3D20803D\n.long 0xC0294788\n.long 0x4E800020\n.long 0x3809FFF3\n.long 0x28000001\n.long 0x4081FFEC\n.long 0xC0230098\n.long 0x4E800020");
}
