// 0x800492E8 InfluenceMap::Validate(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; li 28,0; lwz 0,0x0(29); cmpw 28,0; bge 4f; 0:; lwz 0,0x4(29); li 30,0; addi 27,28,1; cmpw 30,0; bge 3f; 1:; mullw 9,28,0; lwz 11,0x8(29); add 9,9,30; rlwinm 9,9,4,0,27; lwzx 31,9,11; add 9,9,11; cmpwi 31,0; beq 2f; lwz 0,0x4(9); cmpw 31,0; beq 2f; bl _s800492E8_0; lwz 4,0x0(31); bl _s800492E8_1; 2:; lwz 0,0x4(29); addi 30,30,1; cmpw 30,0; blt 1b; 3:; lwz 0,0x0(29); mr 28,27; cmpw 28,0; blt 0b; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800492E8_0();
extern "C" void _s800492E8_1();
extern "C" void f_800492E8() {}
