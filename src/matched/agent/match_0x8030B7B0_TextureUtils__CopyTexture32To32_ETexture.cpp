// 0x8030B7B0 TextureUtils::CopyTexture32To32(ETexture (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 21,0x14(1); stw 0,0x44(1); mr 31,4; mr. 28,3; beq 0f; cmpwi 31,0; beq 0f; lbz 0,0x18(28); cmpwi 0,143; beq 0f; lbz 0,0x18(31); cmpwi 0,143; beq 0f; lbz 0,0x1a(28); cmpwi 0,32; bne 0f; lbz 0,0x1a(31); cmpwi 0,32; beq 1f; 0:; li 3,0; b 4f; 1:; addi 29,1,8; mr 3,28; bl _s8030B7B0_0; li 25,0; mr 21,3; addi 30,1,12; mr 3,31; bl _s8030B7B0_1; lwz 9,0x24(28); mr 22,3; li 4,1; lhz 23,0x12(28); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; lhz 24,0x10(28); add 3,28,3; lhz 26,0x10(31); blrl; lwz 9,0x24(28); mr 5,29; mr 6,30; li 4,0; lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0x24(31); mr 27,3; li 4,2; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x24(31); mr 5,29; mr 6,30; li 4,0; lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; cmplw 25,23; bge 3f; mr 29,27; mr 30,3; rlwinm 26,26,2,0,29; rlwinm 27,24,2,0,29; 2:; mr 3,30; mr 4,29; rlwinm 5,24,2,0,29; addi 25,25,1; crxor 6,6,6; bl _s8030B7B0_2; add 29,29,27; add 30,30,26; cmplw 25,23; blt 2b; 3:; lwz 9,0x24(31); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,31,3; blrl; mr 4,22; mr 3,31; bl _s8030B7B0_3; lwz 9,0x24(28); lha 3,0x70(9); lwz 0,0x74(9); add 3,28,3; mtspr 8,0; blrl; mr 3,28; mr 4,21; bl _s8030B7B0_4; li 3,1; 4:; lwz 0,0x44(1); mtspr 8,0; lmw 21,0x14(1); addi 1,1,64"
extern "C" void _s8030B7B0_0();
extern "C" void _s8030B7B0_1();
extern "C" void _s8030B7B0_2();
extern "C" void _s8030B7B0_3();
extern "C" void _s8030B7B0_4();
extern "C" void f_8030B7B0() {}
