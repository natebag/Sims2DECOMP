// 0x8000FDA8 AptWord::AptWord(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 11,-32707; lis 9,-32707; lfs f0,-10080(11); addi 10,1,8; lfs f13,-10076(9); lis 11,-32698; stfs f0,0x8(1); mr 9,3; stfs f0,0x4(10); addi 11,11,-21112; stw 11,0x2c(9); li 0,0; lwz 6,0x8(1); lwz 7,0x4(10); stfs f13,0x8(1); stfs f13,0x4(10); stw 0,0x18(9); lwz 8,0x4(10); lwz 11,0x8(1); stw 6,0x1c(9); stw 7,0x20(9); stw 11,0x24(9); stw 8,0x28(9); stw 0,0x0(9); stw 0,0x8(9); stw 0,0xc(9); stw 0,0x10(9); stw 0,0x14(9); addi 1,1,16"
extern "C" void f_8000FDA8() {}
