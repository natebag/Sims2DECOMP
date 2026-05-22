// 0x800480E4 EFloorTileGroup::~EFloorTileGroup(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 30,0; lwz 0,0x8(31); mr 28,4; cmpw 30,0; bge 1f; li 29,0; 0:; lwz 10,-26392(13); addi 30,30,1; lwz 9,0xc(31); lwz 11,0x0(10); add 9,29,9; lwz 0,0x12c(11); addi 29,29,16; lha 3,0x128(11); mtspr 8,0; lwz 4,0x8(9); add 3,10,3; blrl; lwz 0,0x8(31); cmpw 30,0; blt 0b; 1:; lwz 3,-26392(13); lwz 4,0x4(31); lwz 9,0x0(3); lha 0,0xa8(9); lwz 9,0xac(9); add 3,3,0; mtspr 8,9; blrl; lwz 3,0x10(31); bl _s800480E4_0; andi. 0,28,1; beq 2f; mr 3,31; bl _s800480E4_1; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800480E4_0();
extern "C" void _s800480E4_1();
extern "C" void f_800480E4() {}
