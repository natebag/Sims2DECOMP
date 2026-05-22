// 0x80027358 HasWallsNotFences(TileWalls (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80027358_0; cmpwi 3,0; li 3,0; beq 5f; mr 3,30; bl _s80027358_1; mr. 31,3; beq 4f; 0:; mr 3,30; mr 4,31; bl _s80027358_2; cmpwi 3,2; beq 1f; cmpwi 3,12; beq 1f; cmpwi 3,13; beq 1f; cmpwi 3,14; bne 2f; 1:; li 0,1; b 3f; 2:; li 0,0; 3:; cmpwi 0,0; li 3,0; bne 5f; mr 4,31; mr 3,30; bl _s80027358_3; mr. 31,3; bne 0b; 4:; li 3,1; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80027358_0();
extern "C" void _s80027358_1();
extern "C" void _s80027358_2();
extern "C" void _s80027358_3();
extern "C" void f_80027358() {}
