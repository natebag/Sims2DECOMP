// 0x803AEB24 _Rb_tree<pair<unsigned (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); mr 26,4; mr 27,3; lwz 29,0x4(26); mr 28,5; li 0,1; lwz 31,0x4(29); 0:; cmpwi 31,0; beq 4f; mr 29,31; lwz 9,0x0(28); lwz 0,0x10(29); li 30,0; cmplw 9,0; blt 1f; cmplw 0,9; blt 2f; addi 3,28,4; addi 4,29,20; bl _s803AEB24_0; cmpwi 3,0; beq 2f; 1:; li 30,1; 2:; mr. 0,30; beq 3f; lwz 31,0x8(31); b 0b; 3:; lwz 31,0xc(31); b 0b; 4:; cmpwi 0,0; stw 29,0x8(1); beq 6f; lwz 9,0x4(26); lwz 0,0x8(9); cmpw 29,0; stw 0,0x10(1); bne 5f; mr 4,26; mr 5,31; mr 6,29; mr 7,28; addi 3,1,24; li 8,0; bl _s803AEB24_1; lwz 9,0x18(1); b 9f; 5:; mr 3,29; bl _s803AEB24_2; stw 3,0x8(1); 6:; lwz 3,0x8(1); li 30,0; lwz 9,0x0(28); lwz 0,0x10(3); cmplw 0,9; blt 7f; cmplw 9,0; blt 8f; addi 3,3,20; addi 4,28,4; bl _s803AEB24_3; cmpwi 3,0; beq 8f; 7:; li 30,1; 8:; cmpwi 30,0; beq 10f; mr 4,26; mr 5,31; mr 6,29; mr 7,28; addi 3,1,16; li 8,0; bl _s803AEB24_4; lwz 9,0x10(1); 9:; li 0,1; stw 0,0x4(27); stw 9,0x0(27); b 11f; 10:; lwz 0,0x8(1); stw 30,0x4(27); stw 0,0x0(27); 11:; mr 3,27; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"
extern "C" void _s803AEB24_0();
extern "C" void _s803AEB24_1();
extern "C" void _s803AEB24_2();
extern "C" void _s803AEB24_3();
extern "C" void _s803AEB24_4();
extern "C" void f_803AEB24() {}
