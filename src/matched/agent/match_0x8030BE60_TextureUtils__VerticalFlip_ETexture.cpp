// 0x8030BE60 TextureUtils::VerticalFlip(ETexture (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr. 27,3; beq 2f; mr 3,27; bl _s8030BE60_0; lwz 9,0x24(27); mr 25,3; li 4,0; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,27,3; blrl; lwz 9,0x24(27); addi 5,1,8; addi 6,1,12; li 4,0; lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,27,3; blrl; lbz 9,0x1a(27); mr 28,3; lhz 0,0x10(27); mullw 0,0,9; rlwinm 29,0,29,3,31; bl _s8030BE60_1; mr 4,29; li 5,0; bl _s8030BE60_2; lhz 9,0x12(27); mr 26,3; addi 0,9,-1; rlwinm 30,9,31,1,31; mullw 0,0,29; cmpwi 30,0; addi 30,30,-1; add 31,28,0; beq 1f; 0:; mr 4,28; mr 5,29; mr 3,26; crxor 6,6,6; bl _s8030BE60_3; mr 4,31; mr 3,28; mr 5,29; add 28,28,29; crxor 6,6,6; bl _s8030BE60_4; mr 3,31; mr 4,26; mr 5,29; subf 31,29,31; crxor 6,6,6; bl _s8030BE60_5; cmpwi 30,0; addi 30,30,-1; bne 0b; 1:; bl _s8030BE60_6; mr 4,26; bl _s8030BE60_7; lwz 9,0x24(27); lha 3,0x70(9); lwz 0,0x74(9); add 3,27,3; mtspr 8,0; blrl; mr 3,27; mr 4,25; bl _s8030BE60_8; 2:; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s8030BE60_0();
extern "C" void _s8030BE60_1();
extern "C" void _s8030BE60_2();
extern "C" void _s8030BE60_3();
extern "C" void _s8030BE60_4();
extern "C" void _s8030BE60_5();
extern "C" void _s8030BE60_6();
extern "C" void _s8030BE60_7();
extern "C" void _s8030BE60_8();
extern "C" void f_8030BE60() {}
