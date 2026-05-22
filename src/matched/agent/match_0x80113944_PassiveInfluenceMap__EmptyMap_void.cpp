// 0x80113944 PassiveInfluenceMap::EmptyMap(void) (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 24,0x28(1); stw 0,0x4c(1); mr 28,3; li 26,0; lwz 0,0x0(28); cmpw 26,0; bge 5f; 0:; lwz 0,0x4(28); li 29,0; addi 24,26,1; cmpw 29,0; bge 4f; addi 31,1,8; li 27,0; addi 30,31,8; addi 25,1,32; 1:; mullw 11,26,0; lwz 8,0x8(28); add 11,11,29; rlwinm 11,11,4,0,27; add 10,8,11; stw 27,0x8(1); stw 27,0x4(31); addi 7,10,8; stw 27,0x4(30); lwzx 0,8,11; lwz 9,0x8(1); stw 0,0x8(1); stwx 9,8,11; lwz 0,0x4(10); lwz 9,0xc(1); stw 0,0xc(1); stw 9,0x4(10); lwz 0,0x4(30); stw 0,0x4(25); lwz 9,0x8(10); lwz 0,0x4(7); stw 9,0x8(31); stw 0,0x4(30); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x8(10); stw 0,0x4(7); lwz 3,0x8(1); cmpwi 3,0; beq 3f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 2f; bl _s80113944_0; b 3f; 2:; bl _s80113944_1; 3:; lwz 0,0x4(28); addi 29,29,1; cmpw 29,0; blt 1b; 4:; lwz 0,0x0(28); mr 26,24; cmpw 26,0; blt 0b; 5:; lwz 0,0x4c(1); mtspr 8,0; lmw 24,0x28(1); addi 1,1,72"
extern "C" void _s80113944_0();
extern "C" void _s80113944_1();
extern "C" void f_80113944() {}
