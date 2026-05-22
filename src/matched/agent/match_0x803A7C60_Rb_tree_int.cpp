// 0x803A7C60 _Rb_tree<int, (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; cmpw 31,29; beq 6f; lwz 0,0x8(31); cmpwi 0,0; beq 0f; lwz 9,0x4(31); lwz 4,0x4(9); bl _s803A7C60_0; lwz 9,0x4(31); li 0,0; stw 9,0x8(9); lwz 11,0x4(31); stw 0,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 0,0x8(31); 0:; li 0,0; stw 0,0x8(31); lbz 9,0xc(29); stb 9,0xc(31); lwz 11,0x4(29); lwz 4,0x4(11); cmpwi 4,0; bne 1f; lwz 9,0x4(31); stw 4,0x4(9); lwz 11,0x4(31); stw 11,0x8(11); lwz 9,0x4(31); stw 9,0xc(9); b 6f; 1:; lwz 30,0x4(31); mr 3,31; mr 5,30; bl _s803A7C60_1; stw 3,0x4(30); lwz 9,0x4(31); addi 11,9,8; lwz 9,0x4(9); b 3f; 2:; lwz 9,0x8(9); 3:; lwz 0,0x8(9); cmpwi 0,0; bne 2b; stw 9,0x0(11); lwz 9,0x4(31); addi 11,9,12; lwz 9,0x4(9); b 5f; 4:; lwz 9,0xc(9); 5:; lwz 0,0xc(9); cmpwi 0,0; bne 4b; stw 9,0x0(11); lwz 0,0x8(29); stw 0,0x8(31); 6:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803A7C60_0();
extern "C" void _s803A7C60_1();
extern "C" void f_803A7C60() {}
