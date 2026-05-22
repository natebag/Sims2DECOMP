// 0x803A9010 _Rb_tree<int, (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 28,4; mr 29,3; lwz 30,0x4(28); mr 27,5; li 0,1; lwz 31,0x4(30); cmpwi 31,0; beq 3f; lwz 9,0x0(27); 0:; mr 30,31; lwz 0,0x10(30); cmpw cr7,9,0; mfcr 0; rlwinm. 0,0,29,31,31; beq 1f; lwz 31,0x8(30); b 2f; 1:; lwz 31,0xc(30); 2:; cmpwi 31,0; bne 0b; 3:; cmpwi 0,0; stw 30,0x8(1); beq 5f; lwz 9,0x4(28); lwz 0,0x8(9); cmpw 30,0; stw 0,0x10(1); bne 4f; mr 4,28; mr 5,31; mr 6,30; mr 7,27; addi 3,1,24; li 8,0; bl _s803A9010_0; lwz 9,0x18(1); b 6f; 4:; mr 3,30; bl _s803A9010_1; stw 3,0x8(1); 5:; lwz 11,0x8(1); lwz 9,0x0(27); lwz 0,0x10(11); cmpw 0,9; bge 7f; mr 4,28; mr 5,31; mr 6,30; mr 7,27; addi 3,1,16; li 8,0; bl _s803A9010_2; lwz 9,0x10(1); 6:; li 0,1; stw 0,0x4(29); stw 9,0x0(29); b 8f; 7:; li 0,0; stw 11,0x0(29); stw 0,0x4(29); 8:; mr 3,29; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s803A9010_0();
extern "C" void _s803A9010_1();
extern "C" void _s803A9010_2();
extern "C" void f_803A9010() {}
