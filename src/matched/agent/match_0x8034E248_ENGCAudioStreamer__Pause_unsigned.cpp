// 0x8034E248 ENGCAudioStreamer::Pause(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; bl _s8034E248_0; mr 3,30; bl _s8034E248_1; cmpwi 3,-1; beq 1f; mulli 30,3,120; lis 9,-32690; addi 29,9,-14064; addi 31,29,28; lwzx 3,31,30; cmpwi 3,0; beq 0f; li 4,0; bl _s8034E248_2; lwzx 3,31,30; li 4,-904; bl _s8034E248_3; 0:; add 9,30,29; lwz 0,0x74(9); oris 0,0,64; stw 0,0x74(9); 1:; bl _s8034E248_4; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8034E248_0();
extern "C" void _s8034E248_1();
extern "C" void _s8034E248_2();
extern "C" void _s8034E248_3();
extern "C" void _s8034E248_4();
extern "C" void f_8034E248() {}
