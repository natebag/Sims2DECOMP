// 0x80149F98 TestDoorCondition(TileWalls (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80149F98_0; mr. 31,3; beq 2f; 0:; and. 0,31,29; bne 1f; mr 4,31; mr 3,30; bl _s80149F98_1; bl _s80149F98_2; cmpwi 3,0; li 3,0; beq 3f; 1:; mr 4,31; mr 3,30; bl _s80149F98_3; mr. 31,3; bne 0b; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80149F98_0();
extern "C" void _s80149F98_1();
extern "C" void _s80149F98_2();
extern "C" void _s80149F98_3();
extern "C" void f_80149F98() {}
