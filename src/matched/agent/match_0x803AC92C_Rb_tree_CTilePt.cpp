// 0x803AC92C _Rb_tree<CTilePt, (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 27,4; mr 29,3; lwz 30,0x4(27); mr 28,5; li 3,1; lwz 31,0x4(30); 0:; cmpwi 31,0; beq 2f; mr 30,31; mr 3,28; addi 4,30,16; bl _s803AC92C_0; mr. 3,3; beq 1f; lwz 31,0x8(30); b 0b; 1:; lwz 31,0xc(30); b 0b; 2:; cmpwi 3,0; stw 30,0x8(1); beq 4f; lwz 9,0x4(27); lwz 0,0x8(9); cmpw 30,0; stw 0,0x10(1); bne 3f; mr 4,27; mr 5,31; mr 6,30; mr 7,28; addi 3,1,24; li 8,0; bl _s803AC92C_1; lwz 9,0x18(1); b 5f; 3:; mr 3,30; bl _s803AC92C_2; stw 3,0x8(1); 4:; lwz 3,0x8(1); mr 4,28; addi 3,3,16; bl _s803AC92C_3; mr. 3,3; beq 6f; mr 4,27; mr 5,31; mr 6,30; mr 7,28; addi 3,1,16; li 8,0; bl _s803AC92C_4; lwz 9,0x10(1); 5:; li 0,1; stw 0,0x4(29); stw 9,0x0(29); b 7f; 6:; lwz 0,0x8(1); stw 3,0x4(29); stw 0,0x0(29); 7:; mr 3,29; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s803AC92C_0();
extern "C" void _s803AC92C_1();
extern "C" void _s803AC92C_2();
extern "C" void _s803AC92C_3();
extern "C" void _s803AC92C_4();
extern "C" void f_803AC92C() {}
