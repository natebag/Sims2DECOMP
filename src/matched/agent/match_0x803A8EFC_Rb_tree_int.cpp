// 0x803A8EFC _Rb_tree<int, (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,4; mr 30,6; lwz 0,0x4(28); mr 27,3; mr 29,7; cmpw 30,0; beq 0f; cmpwi 8,0; bne 2f; cmpwi 5,0; bne 0f; lwz 9,0x0(29); lwz 0,0x10(30); cmpw 9,0; bge 2f; 0:; li 3,24; bl _s803A8EFC_0; lwz 0,0x0(29); mr 31,3; stw 0,0x10(3); lwz 9,0x4(29); stw 9,0x14(3); stw 31,0x8(30); lwz 9,0x4(28); cmpw 30,9; bne 1f; stw 31,0x4(30); lwz 9,0x4(28); b 3f; 1:; lwz 0,0x8(9); cmpw 30,0; bne 4f; stw 31,0x8(9); b 4f; 2:; li 3,24; bl _s803A8EFC_1; lwz 9,0x0(29); mr 31,3; stw 9,0x10(3); lwz 0,0x4(29); stw 0,0x14(3); stw 31,0xc(30); lwz 9,0x4(28); lwz 0,0xc(9); cmpw 30,0; bne 4f; 3:; stw 31,0xc(9); 4:; li 0,0; stw 30,0x4(31); stw 0,0xc(31); mr 3,31; stw 0,0x8(31); lwz 4,0x4(28); addi 4,4,4; bl _s803A8EFC_2; lwz 9,0x8(28); mr 3,27; addi 9,9,1; stw 9,0x8(28); stw 31,0x0(27); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803A8EFC_0();
extern "C" void _s803A8EFC_1();
extern "C" void _s803A8EFC_2();
extern "C" void f_803A8EFC() {}
