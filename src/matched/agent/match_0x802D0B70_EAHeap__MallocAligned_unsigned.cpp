// 0x802D0B70 EAHeap::MallocAligned(unsigned (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,5; mr 30,3; add 4,4,31; neg 0,31; addi 4,4,-1; mr 27,6; and. 29,4,0; mr 28,7; beq 5f; cmplwi 31,8; bgt 0f; mr 3,30; mr 4,29; mr 5,28; bl _s802D0B70_0; b 6f; 0:; bl _s802D0B70_1; cmpw 30,3; beq 1f; lwz 3,-21324(13); mr 4,29; mr 5,31; bl _s802D0B70_2; mr. 0,3; mr 3,0; bne 6f; 1:; mr 3,30; mr 4,29; mr 5,31; mr 6,27; mr 7,28; bl _s802D0B70_3; mr. 0,3; beq 2f; mr 3,0; b 6f; 2:; lwz 3,0x52c(30); cmpwi 3,0; beq 3f; mr 4,29; mr 5,31; mr 6,27; mr 7,28; bl _s802D0B70_4; mr 0,3; 3:; cmpwi 0,0; bne 4f; lwz 3,0x530(30); cmpwi 3,0; beq 4f; mr 4,29; mr 5,31; mr 6,27; mr 7,28; bl _s802D0B70_5; mr 0,3; 4:; mr 3,0; cmpwi 0,0; bne 6f; 5:; li 3,0; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802D0B70_0();
extern "C" void _s802D0B70_1();
extern "C" void _s802D0B70_2();
extern "C" void _s802D0B70_3();
extern "C" void _s802D0B70_4();
extern "C" void _s802D0B70_5();
extern "C" void f_802D0B70() {}
