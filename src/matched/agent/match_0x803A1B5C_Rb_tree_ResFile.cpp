// 0x803A1B5C _Rb_tree<ResFile (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 28,4; mr 29,3; lwz 31,0x4(28); mr 27,5; li 0,1; lwz 30,0x4(31); cmpwi 30,0; beq 3f; lwz 9,0x0(27); 0:; mr 31,30; lwz 0,0x10(31); subfc 0,0,9; subfe 0,0,0; neg. 0,0; beq 1f; lwz 30,0x8(31); b 2f; 1:; lwz 30,0xc(31); 2:; cmpwi 30,0; bne 0b; 3:; cmpwi 0,0; stw 31,0x8(1); beq 5f; lwz 9,0x4(28); lwz 0,0x8(9); cmpw 31,0; stw 0,0x10(1); bne 4f; mr 4,28; mr 5,30; mr 6,31; mr 7,27; addi 3,1,24; li 8,0; bl _s803A1B5C_0; lwz 9,0x18(1); b 6f; 4:; mr 3,31; bl _s803A1B5C_1; stw 3,0x8(1); 5:; lwz 11,0x8(1); lwz 9,0x0(27); lwz 0,0x10(11); cmplw 0,9; bge 7f; mr 4,28; mr 5,30; mr 6,31; mr 7,27; addi 3,1,16; li 8,0; bl _s803A1B5C_2; lwz 9,0x10(1); 6:; li 0,1; stw 0,0x4(29); stw 9,0x0(29); b 8f; 7:; li 0,0; stw 11,0x0(29); stw 0,0x4(29); 8:; mr 3,29; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s803A1B5C_0();
extern "C" void _s803A1B5C_1();
extern "C" void _s803A1B5C_2();
extern "C" void f_803A1B5C() {}
