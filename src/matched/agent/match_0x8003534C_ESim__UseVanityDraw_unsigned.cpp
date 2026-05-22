// 0x8003534C ESim::UseVanityDraw(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x3d4(3); stw 0,0x0(4); lwz 3,0x3dc(3)"
extern "C" void f_8003534C() {}
