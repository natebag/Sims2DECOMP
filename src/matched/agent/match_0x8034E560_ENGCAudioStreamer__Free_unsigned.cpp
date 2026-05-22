// 0x8034E560 ENGCAudioStreamer::Free(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; li 31,0; bl _s8034E560_0; mr 3,30; bl _s8034E560_1; cmpwi 3,-1; beq 2f; mulli 30,3,120; lis 9,-32690; addi 31,9,-14064; add 3,30,31; bl _s8034E560_2; addi 9,31,8; lwzx 3,9,30; cmpwi 3,0; beq 0f; bl _s8034E560_3; 0:; addi 9,31,12; lwzx 3,9,30; cmpwi 3,0; beq 1f; bl _s8034E560_4; 1:; li 31,1; 2:; bl _s8034E560_5; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034E560_0();
extern "C" void _s8034E560_1();
extern "C" void _s8034E560_2();
extern "C" void _s8034E560_3();
extern "C" void _s8034E560_4();
extern "C" void _s8034E560_5();
extern "C" void f_8034E560() {}
