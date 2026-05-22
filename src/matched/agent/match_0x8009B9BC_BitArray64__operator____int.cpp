// 0x8009B9BC BitArray64::operator>>=(int) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 5,4; lwz 3,0x0(30); lwz 4,0x4(30); crxor 6,6,6; bl _s8009B9BC_0; stw 3,0x0(30); stw 4,0x4(30); mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8009B9BC_0();
extern "C" void f_8009B9BC() {}
