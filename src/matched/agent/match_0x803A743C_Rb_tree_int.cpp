// 0x803A743C _Rb_tree<int, (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,3; mr 29,4; mr 28,5; li 3,24; bl _s803A743C_0; lwz 9,0x10(29); mr 27,3; addi 11,29,16; li 10,0; stw 9,0x10(27); lwz 0,0x4(11); stw 0,0x14(27); lwz 9,0x0(29); stw 10,0xc(27); stw 9,0x0(27); stw 28,0x4(27); stw 10,0x8(27); lwz 4,0xc(29); cmpwi 4,0; beq 0f; mr 3,25; mr 5,27; bl _s803A743C_1; stw 3,0xc(27); 0:; lwz 29,0x8(29); mr 28,27; cmpwi 29,0; beq 3f; li 26,0; 1:; li 3,24; addi 30,29,16; bl _s803A743C_2; lwz 0,0x10(29); mr 31,3; stw 0,0x10(31); lwz 9,0x4(30); stw 9,0x14(31); lwz 0,0x0(29); stw 26,0x8(31); stw 0,0x0(31); stw 26,0xc(31); stw 31,0x8(28); stw 28,0x4(31); lwz 4,0xc(29); cmpwi 4,0; beq 2f; mr 3,25; mr 5,31; bl _s803A743C_3; stw 3,0xc(31); 2:; lwz 29,0x8(29); mr 28,31; cmpwi 29,0; bne 1b; 3:; mr 3,27; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s803A743C_0();
extern "C" void _s803A743C_1();
extern "C" void _s803A743C_2();
extern "C" void _s803A743C_3();
extern "C" void f_803A743C() {}
