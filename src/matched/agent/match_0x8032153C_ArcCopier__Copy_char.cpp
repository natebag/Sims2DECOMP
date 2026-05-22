// 0x8032153C ArcCopier::Copy(char (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 0,-26640(13); mr 30,3; mr 31,5; mr 28,6; cmpwi 0,0; bne 1f; stw 0,0x0(28); stw 0,0x8(30); stw 7,0xc(30); lwz 11,-22652(13); lwz 9,0x0(11); lha 3,0xa0(9); lwz 0,0xa4(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; stw 3,0x0(30); beq 1f; lis 6,-32702; lis 3,-32694; addi 3,3,-10620; mr 5,31; addi 6,6,2872; addi 4,30,4; li 7,0; lis 8,-32768; li 9,0; bl _s8032153C_0; cmpwi 3,0; bne 2f; b 1f; 0:; bl _s8032153C_1; mr 4,29; bl _s8032153C_2; 1:; li 3,0; b 8f; 2:; bl _s8032153C_3; li 4,0; li 5,64; ori 4,4,32768; li 6,0; li 7,0; bl _s8032153C_4; mr. 29,3; beq 7f; b 4f; 3:; lwz 0,-26640(13); cmpwi 0,0; bne 6f; 4:; bl _s8032153C_5; li 31,0; lwz 6,0x8(30); ori 31,31,32768; lwz 0,0xc(30); subf 0,6,0; cmpwi 0,32767; bgt 5f; mr 31,0; 5:; lwz 3,-22652(13); mr 5,29; lwz 4,0x0(30); mr 7,31; lwz 11,0x0(3); li 8,1; li 9,0; lha 0,0x78(11); lwz 11,0x7c(11); add 3,3,0; mtspr 8,11; blrl; cmpw 31,3; bne 0b; bl _s8032153C_6; lwz 3,-22652(13); mr 5,29; lwz 4,0x4(30); mr 7,31; lwz 11,0x0(3); li 8,1; lwz 6,0x8(30); li 9,0; lha 0,0x80(11); lwz 11,0x84(11); add 3,3,0; mtspr 8,11; blrl; cmpw 31,3; bne 0b; lwz 0,0x8(30); add 0,0,31; stw 0,0x8(30); stw 0,0x0(28); lwz 9,0x8(30); lwz 0,0xc(30); cmpw 9,0; blt 3b; 6:; bl _s8032153C_7; mr 4,29; bl _s8032153C_8; 7:; lwz 0,0xc(30); lwz 3,0x8(30); xor 3,3,0; subfic 9,3,0; adde 3,9,3; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8032153C_0();
extern "C" void _s8032153C_1();
extern "C" void _s8032153C_2();
extern "C" void _s8032153C_3();
extern "C" void _s8032153C_4();
extern "C" void _s8032153C_5();
extern "C" void _s8032153C_6();
extern "C" void _s8032153C_7();
extern "C" void _s8032153C_8();
extern "C" void f_8032153C() {}
