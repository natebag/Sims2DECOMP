// 0x802D7D04 ENgcSNFile::Creator(EFile (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,6; mr 28,7; mr 29,4; mr 30,5; bl _s802D7D04_0; li 4,64; li 5,0; bl _s802D7D04_1; bl _s802D7D04_2; lwz 9,-26836(13); mr 31,3; li 11,0; li 0,1; stw 0,0x3c(31); cmpwi 9,0; stw 11,0x38(31); stw 11,0x30(31); beq 0f; stw 11,-26836(13); bl _s802D7D04_3; 0:; lis 4,-32702; mr 3,30; addi 4,4,-6664; bl _s802D7D04_4; subfic 0,3,0; adde 30,0,3; li 5,0; mr 3,29; mr 4,30; bl _s802D7D04_5; cmpwi 3,-1; stw 3,0x2c(31); bne 3f; cmpwi 30,1; bne 1f; mr 3,29; li 4,0; bl _s802D7D04_6; stw 3,0x2c(31); 1:; lwz 0,0x2c(31); cmpwi 0,-1; bne 3f; cmpwi 31,0; beq 2f; lwz 9,0x28(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 2:; li 3,0; b 4f; 3:; lwz 3,0x2c(31); li 4,0; li 5,2; bl _s802D7D04_7; stw 3,0x14(31); li 4,0; lwz 3,0x2c(31); li 5,0; bl _s802D7D04_8; lis 0,-32768; stw 28,0xc(31); stw 27,0x10(31); mr 3,31; stw 0,0x8(31); 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802D7D04_0();
extern "C" void _s802D7D04_1();
extern "C" void _s802D7D04_2();
extern "C" void _s802D7D04_3();
extern "C" void _s802D7D04_4();
extern "C" void _s802D7D04_5();
extern "C" void _s802D7D04_6();
extern "C" void _s802D7D04_7();
extern "C" void _s802D7D04_8();
extern "C" void f_802D7D04() {}
