// 0x800488BC InfluenceMap::~InfluenceMap(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s800488BC_0; lwz 9,0x8(30); cmpwi 9,0; beq 4f; lwz 0,-8(9); rlwinm 0,0,4,0,27; add 31,9,0; cmpw 9,31; beq 3f; 0:; lwzu 3,-16(31); cmpwi 3,0; beq 2f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 1f; bl _s800488BC_1; b 2f; 1:; bl _s800488BC_2; 2:; lwz 0,0x8(30); cmpw 0,31; bne 0b; 3:; lwz 3,0x8(30); addi 3,3,-8; bl _s800488BC_3; 4:; li 0,0; andi. 9,29,1; stw 0,0x8(30); beq 5f; mr 3,30; bl _s800488BC_4; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800488BC_0();
extern "C" void _s800488BC_1();
extern "C" void _s800488BC_2();
extern "C" void _s800488BC_3();
extern "C" void _s800488BC_4();
extern "C" void f_800488BC() {}
