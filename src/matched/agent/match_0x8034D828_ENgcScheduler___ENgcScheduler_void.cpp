// 0x8034D828 ENgcScheduler::~ENgcScheduler(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; addi 9,9,-12800; mr 29,4; stw 9,0x338(30); addi 3,30,928; li 4,2; bl _s8034D828_0; addi 3,30,916; li 4,2; bl _s8034D828_1; addi 3,30,840; li 4,2; bl _s8034D828_2; lis 9,-32697; mr 3,30; addi 9,9,-12688; mr 4,29; stw 9,0x338(30); bl _s8034D828_3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8034D828_0();
extern "C" void _s8034D828_1();
extern "C" void _s8034D828_2();
extern "C" void _s8034D828_3();
extern "C" void f_8034D828() {}
