// 0x8034E0E8 ENGCAudioStreamer::~ENGCAudioStreamer(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32690; mr 29,3; addi 9,9,-14064; mr 28,4; addi 31,9,224; li 30,1; 0:; lwz 3,-76(31); bl _s8034E0E8_0; lwz 3,-76(31); bl _s8034E0E8_1; lwz 4,-100(31); mr 3,29; bl _s8034E0E8_2; bl _s8034E0E8_3; cmpwi 3,0; bne 1f; bl _s8034E0E8_4; lwz 4,0x0(31); bl _s8034E0E8_5; 1:; addi 31,31,-120; addic. 30,30,-1; bge 0b; andi. 0,28,1; beq 2f; mr 3,29; bl _s8034E0E8_6; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8034E0E8_0();
extern "C" void _s8034E0E8_1();
extern "C" void _s8034E0E8_2();
extern "C" void _s8034E0E8_3();
extern "C" void _s8034E0E8_4();
extern "C" void _s8034E0E8_5();
extern "C" void _s8034E0E8_6();
extern "C" void f_8034E0E8() {}
