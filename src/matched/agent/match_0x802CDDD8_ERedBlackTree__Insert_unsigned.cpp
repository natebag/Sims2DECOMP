// 0x802CDDD8 ERedBlackTree::Insert(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; mr 29,5; cmpwi 6,0; beq 0f; bl _s802CDDD8_0; mr 4,3; mr 5,31; mr 3,30; b 2f; 0:; mr 4,31; mr 3,30; bl _s802CDDD8_1; mr. 4,3; beq 1f; lwz 0,0x18(4); li 3,0; cmpw 0,31; beq 3f; 1:; mr 3,30; mr 5,31; 2:; mr 6,29; bl _s802CDDD8_2; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802CDDD8_0();
extern "C" void _s802CDDD8_1();
extern "C" void _s802CDDD8_2();
extern "C" void f_802CDDD8() {}
