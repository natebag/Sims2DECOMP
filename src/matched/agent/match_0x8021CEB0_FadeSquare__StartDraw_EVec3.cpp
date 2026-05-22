// 0x8021CEB0 FadeSquare::StartDraw(EVec3 (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32704; lwz 10,0x8(4); lfs f0,-9144(9); li 11,0; lwz 0,0x0(4); lwz 9,0x4(4); stw 5,0x18(3); stw 0,0x0(3); stw 9,0x4(3); stw 10,0x8(3); stfs f0,0x10(3); stw 11,0x14(3)"
extern "C" void f_8021CEB0() {}
