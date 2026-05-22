// 0x8034E2C8 ENGCAudioStreamer::Resume(unsigned (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; bl _s8034E2C8_0; mr 3,30; bl _s8034E2C8_1; cmpwi 3,-1; beq 0f; mulli 31,3,120; lis 9,-32690; addi 9,9,-14064; addi 29,9,28; add 30,31,9; lwz 0,0x74(30); rlwinm 0,0,0,10,8; stw 0,0x74(30); lwzx 3,29,31; cmpwi 3,0; beq 0f; li 4,1; bl _s8034E2C8_2; lbz 3,0x14(30); lwzx 30,29,31; bl _s8034E2C8_3; mr 4,3; mr 3,30; bl _s8034E2C8_4; 0:; bl _s8034E2C8_5; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8034E2C8_0();
extern "C" void _s8034E2C8_1();
extern "C" void _s8034E2C8_2();
extern "C" void _s8034E2C8_3();
extern "C" void _s8034E2C8_4();
extern "C" void _s8034E2C8_5();
extern "C" void f_8034E2C8() {}
