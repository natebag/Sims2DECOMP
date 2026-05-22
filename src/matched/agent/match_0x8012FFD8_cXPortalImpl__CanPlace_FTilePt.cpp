// 0x8012FFD8 cXPortalImpl::CanPlace(FTilePt (728 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 26,0x60(1); stw 0,0x7c(1); mr 31,3; mr 27,4; lwz 3,0x0(31); mr 26,5; lwz 0,0xc(3); cmpwi 0,0; beq 0f; lwz 9,0x0(27); lwz 10,0x4(27); addi 5,1,72; addi 8,1,80; stw 9,0x50(1); stw 10,0x54(1); mr 4,8; lwz 0,0x1c(3); lwz 9,0x20(3); rlwinm 0,0,4,0,27; rlwinm 9,9,4,0,27; stw 0,0x4(5); stw 9,0x48(1); lwz 11,0x4(5); lwz 0,0x4(8); subf 0,11,0; stw 0,0x4(8); lwz 9,0x50(1); lwz 0,0x48(1); subf 9,0,9; stw 9,0x50(1); lwz 11,0xc(3); lwz 5,0x24(3); lwz 10,0x4(11); subf 5,5,26; lwz 11,0x0(10); lwz 9,0x4(11); lha 3,0x130(9); lwz 0,0x134(9); add 3,11,3; mtspr 8,0; blrl; b 8f; 0:; mr 4,27; mr 5,26; bl _s8012FFD8_0; cmpwi 3,0; bne 1f; li 3,0; b 8f; 1:; lwz 11,0x0(31); lwz 29,-21488(13); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; b 5f; 2:; lwz 9,0x0(30); li 4,11; lwz 3,0x0(9); bl _s8012FFD8_1; mr 31,3; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 4f; lwz 9,0x0(31); lwz 11,0x0(9); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x2a0(9); lwz 0,0x2a4(9); add 3,10,3; mtspr 8,0; blrl; mr. 28,3; beq 4f; mr 5,26; addi 3,1,8; mr 4,27; bl _s8012FFD8_2; addi 3,1,8; bl _s8012FFD8_3; lwz 9,0x0(31); lwz 0,0x1c(9); add 4,3,0; addi 3,1,8; bl _s8012FFD8_4; addi 3,1,8; bl _s8012FFD8_5; lwz 9,0x0(31); lwz 0,0x20(9); add 4,3,0; addi 3,1,8; bl _s8012FFD8_6; lwz 9,0x0(31); addi 3,1,8; lwz 4,0x24(9); add 4,26,4; bl _s8012FFD8_7; lwz 9,0x0(29); addi 4,1,8; lha 3,0x58(9); lwz 0,0x5c(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 3,0; bne 3f; lwz 9,0x0(29); addi 31,1,16; mr 3,31; addi 5,1,8; lha 4,0xa8(9); lwz 0,0xac(9); add 4,29,4; mtspr 8,0; blrl; mr 4,28; mr 3,31; bl _s8012FFD8_8; cmpwi 3,1; bne 6f; mr 3,31; li 4,2; bl _s8012FFD8_9; 3:; addi 3,1,8; li 4,2; bl _s8012FFD8_10; 4:; lwz 9,0x4(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; 5:; mtspr 8,0; blrl; mr. 30,3; bne 2b; lwz 9,0x0(27); lwz 10,0x4(27); addi 11,1,88; mr 3,27; mr 4,11; stw 9,0x58(1); stw 10,0x5c(1); lwz 0,0x4(11); rlwinm 0,0,0,0,27; ori 0,0,8; stw 0,0x4(11); lwz 9,0x58(1); rlwinm 9,9,0,0,27; ori 9,9,8; stw 9,0x58(1); bl _s8012FFD8_11; cmpwi 3,1; bne 7f; li 3,1; b 8f; 6:; li 0,22; mr 3,31; stw 0,-31888(13); li 4,2; bl _s8012FFD8_12; addi 3,1,8; li 4,2; bl _s8012FFD8_13; li 3,0; b 8f; 7:; li 0,3; li 3,0; stw 0,-31888(13); 8:; lwz 0,0x7c(1); mtspr 8,0; lmw 26,0x60(1); addi 1,1,120"
extern "C" void _s8012FFD8_0();
extern "C" void _s8012FFD8_1();
extern "C" void _s8012FFD8_2();
extern "C" void _s8012FFD8_3();
extern "C" void _s8012FFD8_4();
extern "C" void _s8012FFD8_5();
extern "C" void _s8012FFD8_6();
extern "C" void _s8012FFD8_7();
extern "C" void _s8012FFD8_8();
extern "C" void _s8012FFD8_9();
extern "C" void _s8012FFD8_10();
extern "C" void _s8012FFD8_11();
extern "C" void _s8012FFD8_12();
extern "C" void _s8012FFD8_13();
extern "C" void f_8012FFD8() {}
