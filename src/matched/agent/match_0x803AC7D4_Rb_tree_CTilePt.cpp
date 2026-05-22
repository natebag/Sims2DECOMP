// 0x803AC7D4 _Rb_tree<CTilePt, (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,4; mr 28,6; lwz 0,0x4(27); mr 26,3; mr 29,7; cmpw 28,0; beq 0f; cmpwi 8,0; bne 2f; cmpwi 5,0; bne 0f; mr 3,29; addi 4,28,16; bl _s803AC7D4_0; cmpwi 3,0; beq 2f; 0:; li 3,36; bl _s803AC7D4_1; mr 30,3; mr 4,29; addi 3,30,16; mr 31,30; bl _s803AC7D4_2; lwz 9,0x4(29); lwz 10,0x8(29); stw 9,0x14(30); stw 10,0x18(30); lwz 11,0xc(29); lwz 12,0x10(29); stw 11,0x1c(30); stw 12,0x20(30); stw 31,0x8(28); lwz 9,0x4(27); cmpw 28,9; bne 1f; stw 31,0x4(28); lwz 9,0x4(27); b 3f; 1:; lwz 0,0x8(9); cmpw 28,0; bne 4f; stw 31,0x8(9); b 4f; 2:; li 3,36; bl _s803AC7D4_3; mr 30,3; mr 4,29; addi 3,30,16; mr 31,30; bl _s803AC7D4_4; lwz 9,0x4(29); lwz 10,0x8(29); stw 9,0x14(30); stw 10,0x18(30); lwz 11,0xc(29); lwz 12,0x10(29); stw 11,0x1c(30); stw 12,0x20(30); stw 31,0xc(28); lwz 9,0x4(27); lwz 0,0xc(9); cmpw 28,0; bne 4f; 3:; stw 31,0xc(9); 4:; li 0,0; stw 28,0x4(31); stw 0,0xc(31); mr 3,31; stw 0,0x8(31); lwz 4,0x4(27); addi 4,4,4; bl _s803AC7D4_5; lwz 9,0x8(27); mr 3,26; addi 9,9,1; stw 9,0x8(27); stw 31,0x0(26); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s803AC7D4_0();
extern "C" void _s803AC7D4_1();
extern "C" void _s803AC7D4_2();
extern "C" void _s803AC7D4_3();
extern "C" void _s803AC7D4_4();
extern "C" void _s803AC7D4_5();
extern "C" void f_803AC7D4() {}
