// 0x8034D9F0 ENgcScheduler::Main(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; addi 30,1,8; 0:; mr 4,30; addi 3,31,840; li 5,1; bl _s8034D9F0_0; lwz 4,0x8(1); mr 3,31; bl _s8034D9F0_1; b 0b"
extern "C" void _s8034D9F0_0();
extern "C" void _s8034D9F0_1();
extern "C" void f_8034D9F0() {}
