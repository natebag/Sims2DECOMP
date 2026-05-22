// 0x80357788 DepthOfField::SetTargetSettings(DepthOfFieldSettings (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,0x0(4); addi 9,3,20; lwz 0,0x4(4); lwz 11,0x8(4); lwz 10,0xc(4); stw 8,0x14(3); stw 0,0x4(9); stw 11,0x8(9); stw 10,0xc(9); lwz 0,0x10(4); stw 0,0x10(9)"
extern "C" void f_80357788() {}
