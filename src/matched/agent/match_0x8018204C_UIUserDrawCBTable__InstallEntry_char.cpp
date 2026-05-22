// 0x8018204C UIUserDrawCBTable::InstallEntry(char (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x8(31); mr 30,5; mr 28,6; cmpwi 0,0; beq 0f; bl _s8018204C_0; cmpwi 3,0; bne 0f; mr 3,31; mr 4,29; mr 5,30; mr 6,28; bl _s8018204C_1; li 3,1; b 1f; 0:; mr 3,30; bl _s8018204C_2; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8018204C_0();
extern "C" void _s8018204C_1();
extern "C" void _s8018204C_2();
extern "C" void f_8018204C() {}
