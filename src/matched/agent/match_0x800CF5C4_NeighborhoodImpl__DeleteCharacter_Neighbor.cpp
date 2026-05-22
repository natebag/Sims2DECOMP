// 0x800CF5C4 NeighborhoodImpl::DeleteCharacter(Neighbor (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 27,4; mr 26,3; mr 3,27; bl _s800CF5C4_0; cmpwi 3,0; bne 1f; 0:; li 3,-1; b 6f; 1:; lwz 25,0xc(27); mr 3,25; bl _s800CF5C4_1; addi 9,26,92; lwz 31,0x5c(26); lwz 0,0x4(9); mr 28,3; lwz 29,-21484(13); mr 30,9; cmpw 31,0; beq 4f; 2:; lwz 3,0x0(31); mr 4,28; lwz 9,0x0(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0b; lwz 0,0x4(30); addi 31,31,4; cmpw 31,0; bne 2b; b 4f; 3:; lwz 9,0x4(31); lwz 0,0x32c(9); lha 3,0x328(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x4(31); mr 30,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(29); mr 4,30; lha 3,0x90(9); lwz 0,0x94(9); add 3,29,3; mtspr 8,0; blrl; 4:; lwz 9,0x0(29); mr 4,28; lha 3,0xe0(9); lwz 0,0xe4(9); add 3,29,3; mtspr 8,0; blrl; mr. 31,3; bne 3b; lwz 31,-21508(13); mr 3,27; bl _s800CF5C4_2; cmpwi 3,0; beq 5f; lwz 9,0x0(31); mr 4,25; lha 3,0xb8(9); lwz 0,0xbc(9); add 3,31,3; mtspr 8,0; blrl; 5:; mr 3,26; mr 4,27; bl _s800CF5C4_3; li 3,0; 6:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s800CF5C4_0();
extern "C" void _s800CF5C4_1();
extern "C" void _s800CF5C4_2();
extern "C" void _s800CF5C4_3();
extern "C" void f_800CF5C4() {}
