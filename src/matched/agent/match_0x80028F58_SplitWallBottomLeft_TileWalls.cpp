// 0x80028F58 SplitWallBottomLeft(TileWalls (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,8; bl _s80028F58_0; mr 3,30; li 4,1; bl _s80028F58_1; cmpwi 3,0; li 3,1; bne 0f; li 3,0; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80028F58_0();
extern "C" void _s80028F58_1();
extern "C" void f_80028F58() {}
