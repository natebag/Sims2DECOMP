// 0x802D0AA4 EAHeap::Malloc(unsigned (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,5; mr. 30,4; beq 4f; bl _s802D0AA4_0; cmpw 31,3; beq 0f; lwz 3,-21324(13); mr 4,30; li 5,8; bl _s802D0AA4_1; mr. 0,3; mr 3,0; bne 5f; 0:; mr 3,31; mr 4,30; mr 5,29; bl _s802D0AA4_2; mr. 0,3; beq 1f; mr 3,0; b 5f; 1:; lwz 3,0x52c(31); cmpwi 3,0; beq 2f; mr 4,30; mr 5,29; bl _s802D0AA4_3; mr 0,3; 2:; cmpwi 0,0; bne 3f; lwz 3,0x530(31); cmpwi 3,0; beq 3f; mr 4,30; mr 5,29; bl _s802D0AA4_4; mr 0,3; 3:; mr 3,0; cmpwi 0,0; bne 5f; 4:; li 3,0; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D0AA4_0();
extern "C" void _s802D0AA4_1();
extern "C" void _s802D0AA4_2();
extern "C" void _s802D0AA4_3();
extern "C" void _s802D0AA4_4();
extern "C" void f_802D0AA4() {}
