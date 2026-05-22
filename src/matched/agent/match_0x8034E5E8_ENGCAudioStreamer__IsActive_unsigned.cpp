// 0x8034E5E8 ENGCAudioStreamer::IsActive(unsigned (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; li 31,0; bl _s8034E5E8_0; mr 3,30; bl _s8034E5E8_1; cmpwi 3,-1; beq 0f; mulli 0,3,120; lis 9,-32690; addi 9,9,-14064; lwzx 11,9,0; cmpwi 11,0; beq 0f; li 31,1; 0:; bl _s8034E5E8_2; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034E5E8_0();
extern "C" void _s8034E5E8_1();
extern "C" void _s8034E5E8_2();
extern "C" void f_8034E5E8() {}
