// 0x802D0C84 EAHeap::Calloc(unsigned (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,4; mr 28,5; mullw. 26,29,28; mr 30,3; mr 27,6; beq 4f; bl _s802D0C84_0; cmpw 30,3; beq 0f; lwz 3,-21324(13); mr 4,26; li 5,8; bl _s802D0C84_1; mr. 31,3; beq 0f; mr 5,26; mr 3,31; li 4,0; bl _s802D0C84_2; mr 3,31; b 5f; 0:; mr 3,30; mr 4,29; mr 5,28; mr 6,27; bl _s802D0C84_3; mr. 31,3; beq 1f; mr 3,31; b 5f; 1:; lwz 3,0x52c(30); cmpwi 3,0; beq 2f; mr 4,29; mr 5,28; mr 6,27; bl _s802D0C84_4; mr 31,3; 2:; cmpwi 31,0; bne 3f; lwz 3,0x530(30); cmpwi 3,0; beq 3f; mr 4,29; mr 5,28; mr 6,27; bl _s802D0C84_5; mr 31,3; 3:; mr 3,31; cmpwi 31,0; bne 5f; 4:; li 3,0; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802D0C84_0();
extern "C" void _s802D0C84_1();
extern "C" void _s802D0C84_2();
extern "C" void _s802D0C84_3();
extern "C" void _s802D0C84_4();
extern "C" void _s802D0C84_5();
extern "C" void f_802D0C84() {}
