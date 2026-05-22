// 0x8029E7E0 AptLoader::AllImportsAvailable(AptSharedPtr<AptFile>) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 31,4; li 29,0; lwz 9,0x0(31); mr 26,3; li 27,1; lwz 11,0x10(9); lwz 0,0x28(11); cmpw 29,0; bge 4f; li 28,0; 0:; lwz 9,0x0(31); addi 3,1,16; lwz 11,0x10(9); lwz 10,0x2c(11); lwzx 4,28,10; bl _s8029E7E0_0; addi 3,1,8; mr 4,26; addi 5,1,16; bl _s8029E7E0_1; lwz 3,0x8(1); cmpwi 3,0; mfcr 30; rlwinm 30,30,3,31,31; beq 1f; bl _s8029E7E0_2; cmpwi 3,0; bne 1f; lwz 3,0x8(1); bl _s8029E7E0_3; 1:; lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029E7E0_4; 2:; cmpwi 30,0; beq 3f; li 27,0; b 4f; 3:; lwz 9,0x0(31); addi 29,29,1; addi 28,28,16; lwz 11,0x10(9); lwz 0,0x28(11); cmpw 29,0; bge 4f; cmpwi 27,0; bne 0b; 4:; lwz 3,0x0(31); cmpwi 3,0; beq 5f; bl _s8029E7E0_5; cmpwi 3,0; bne 5f; lwz 3,0x0(31); bl _s8029E7E0_6; 5:; mr 3,27; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s8029E7E0_0();
extern "C" void _s8029E7E0_1();
extern "C" void _s8029E7E0_2();
extern "C" void _s8029E7E0_3();
extern "C" void _s8029E7E0_4();
extern "C" void _s8029E7E0_5();
extern "C" void _s8029E7E0_6();
extern "C" void f_8029E7E0() {}
