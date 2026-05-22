// 0x80195C80 CASTarget::ConvertPartUIFocusToModList(char (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); li 0,0; mr 30,3; stw 0,0x8(1); mr 26,4; li 31,0; addi 29,1,24; addi 27,1,16; li 28,1; 0:; lwz 3,0xa4(30); mr 4,31; mr 5,29; bl _s80195C80_0; cmpwi 3,0; beq 3f; lwz 9,0x84(30); lwz 3,0x10(9); cmpwi 3,0; beq 3f; lbz 4,0x3(29); bl _s80195C80_1; cmpwi 3,0; beq 1f; lwz 0,0x8(1); slw 9,28,31; or 0,0,9; b 2f; 1:; lwz 9,0x8(1); slw 0,28,31; andc 0,9,0; 2:; stw 0,0x8(1); 3:; addi 31,31,1; cmpwi 31,6; ble 0b; lwz 0,0x8(1); mr 3,30; mr 4,26; mr 5,27; ori 0,0,128; stw 0,0x10(1); stw 0,0x8(1); bl _s80195C80_2; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"
extern "C" void _s80195C80_0();
extern "C" void _s80195C80_1();
extern "C" void _s80195C80_2();
extern "C" void f_80195C80() {}
