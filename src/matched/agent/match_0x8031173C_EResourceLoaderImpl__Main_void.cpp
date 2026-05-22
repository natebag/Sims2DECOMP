// 0x8031173C EResourceLoaderImpl::Main(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; addi 29,1,8; li 27,0; li 28,1; 0:; stw 27,0x3e4(31); mr 4,29; addi 3,31,888; li 5,1; bl _s8031173C_0; lwz 0,0x3e8(31); mr 30,3; li 4,-1; addi 3,31,1004; cmpwi 0,0; beq 1f; bl _s8031173C_1; 1:; mr 3,31; cmpwi 30,0; stw 28,0x3e4(31); beq 0b; lwz 4,0x8(1); bl _s8031173C_2; b 0b"
extern "C" void _s8031173C_0();
extern "C" void _s8031173C_1();
extern "C" void _s8031173C_2();
extern "C" void f_8031173C() {}
