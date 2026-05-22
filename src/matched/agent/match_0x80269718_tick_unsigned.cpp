// 0x80269718 _tick(unsigned (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 9,-23008(13); mr 29,3; li 27,0; li 30,0; lwz 11,0x28(9); lwz 10,0x0(11); lwz 31,0x54(10); mr 3,31; bl _s80269718_0; cmpwi 3,18; bne 0f; mr 3,31; bl _s80269718_1; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; bne 2f; li 3,0; b 8f; 1:; li 3,1; b 8f; 2:; lwz 11,-23008(13); lwz 10,0x28(11); mr 3,11; lwz 9,0x0(10); lwz 11,0x54(9); lwz 10,0x4c(11); lwz 9,0x8(10); lwz 0,0x30(10); lwz 30,0x24(9); add 29,29,0; cmplw 29,30; blt 5f; li 27,1; 3:; mr 4,30; subf 29,30,29; bl _s80269718_2; li 28,0; lwz 3,-23008(13); addi 3,3,40; bl _s80269718_3; lwz 3,-23008(13); bl _s80269718_4; lwz 3,-23008(13); bl _s80269718_5; lwz 3,-22996(13); bl _s80269718_6; lwz 9,-23008(13); lwz 0,-23012(13); lwz 11,0x28(9); add 0,0,30; lwz 9,0x0(11); stw 0,-23012(13); lwz 31,0x54(9); mr 3,31; bl _s80269718_7; cmpwi 3,18; bne 4f; mr 3,31; bl _s80269718_8; subfic 0,3,0; adde 28,0,3; 4:; cmpwi 28,0; beq 1b; lwz 0,-27608(13); lwz 3,-23008(13); cmpwi 0,0; bne 5f; cmplw 29,30; bge 3b; 5:; lwz 11,0x28(3); li 30,0; lwz 9,0x0(11); lwz 31,0x54(9); mr 3,31; bl _s80269718_9; cmpwi 3,18; bne 6f; mr 3,31; bl _s80269718_10; subfic 0,3,0; adde 30,0,3; 6:; cmpwi 30,0; beq 7f; lwz 9,-23008(13); lwz 11,0x28(9); lwz 10,0x0(11); lwz 9,0x54(10); lwz 11,0x4c(9); stw 29,0x30(11); 7:; mr 3,27; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80269718_0();
extern "C" void _s80269718_1();
extern "C" void _s80269718_2();
extern "C" void _s80269718_3();
extern "C" void _s80269718_4();
extern "C" void _s80269718_5();
extern "C" void _s80269718_6();
extern "C" void _s80269718_7();
extern "C" void _s80269718_8();
extern "C" void _s80269718_9();
extern "C" void _s80269718_10();
extern "C" void f_80269718() {}
