// 0x8031BA74 ERQuickdata::getTable(char (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; mr. 4,4; beq 0f; lwz 9,0x14(31); mr 6,4; li 4,0; lwz 5,0x8(9); addi 5,5,-1; bl _s8031BA74_0; mr. 3,3; blt 0f; mulli 9,3,20; lwz 0,0x14(31); addi 9,9,24; add 30,0,9; 0:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8031BA74_0();
extern "C" void f_8031BA74() {}
