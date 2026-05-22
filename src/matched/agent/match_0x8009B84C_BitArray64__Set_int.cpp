// 0x8009B84C BitArray64::Set(int) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 5,4; li 3,0; li 4,1; crxor 6,6,6; bl _s8009B84C_0; lwz 9,0x0(30); lwz 10,0x4(30); or 9,9,3; or 10,10,4; stw 9,0x0(30); stw 10,0x4(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8009B84C_0();
extern "C" void f_8009B84C() {}
