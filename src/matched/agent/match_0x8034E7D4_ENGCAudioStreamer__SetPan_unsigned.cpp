// 0x8034E7D4 ENGCAudioStreamer::SetPan(unsigned (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,5; bl _s8034E7D4_0; mr 3,30; bl _s8034E7D4_1; cmpwi 3,-1; beq 0f; mulli 3,3,120; lis 9,-32690; addi 11,9,-14064; lwzx 0,11,3; cmpwi 0,0; beq 0f; add 9,3,11; stb 31,0x15(9); addi 11,11,28; lwzx 3,11,3; cmpwi 3,0; beq 0f; mr 4,31; bl _s8034E7D4_2; 0:; bl _s8034E7D4_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034E7D4_0();
extern "C" void _s8034E7D4_1();
extern "C" void _s8034E7D4_2();
extern "C" void _s8034E7D4_3();
extern "C" void f_8034E7D4() {}
