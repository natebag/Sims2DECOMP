// 0x8032D8A8 __static_initialization_and_destruction_0 (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 3f; cmpwi 3,0; beq 0f; lis 3,-32692; addi 3,3,14816; bl _s8032D8A8_0; lis 9,-32692; li 0,0; addi 9,9,18184; stw 0,0x8(9); stw 0,0x4(9); b 3f; 0:; lis 9,-32692; addi 30,9,18184; b 2f; 1:; lwz 0,0x0(31); stw 0,0x4(30); bl _s8032D8A8_1; mr 4,31; bl _s8032D8A8_2; 2:; lwz 31,0x4(30); cmpwi 31,0; bne 1b; li 0,0; lis 3,-32692; stw 0,0x8(30); addi 3,3,14816; li 4,2; bl _s8032D8A8_3; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032D8A8_0();
extern "C" void _s8032D8A8_1();
extern "C" void _s8032D8A8_2();
extern "C" void _s8032D8A8_3();
extern "C" void f_8032D8A8() {}
