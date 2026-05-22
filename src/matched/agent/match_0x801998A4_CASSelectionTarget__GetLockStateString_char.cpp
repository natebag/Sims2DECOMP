// 0x801998A4 CASSelectionTarget::GetLockStateString(char (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 23,0x2c(1); stw 0,0x54(1); mr 30,3; mr 23,4; addi 3,1,8; li 4,0; li 5,17; addi 28,30,748; bl _s801998A4_0; li 31,0; li 3,0; addi 29,1,8; stb 3,0x20(1); li 24,0; li 25,49; li 26,50; li 27,48; 0:; mr 3,30; mr 4,31; bl _s801998A4_1; mr. 3,3; blt 1f; lwz 0,0x8c(30); cmpw 3,0; blt 2f; 1:; stb 24,0x20(1); b 3f; 2:; lbzx 0,28,3; stb 0,0x20(1); 3:; lbz 0,0x20(1); andi. 9,0,2; beq 4f; stbx 25,29,31; b 6f; 4:; andi. 9,0,4; beq 5f; stbx 26,29,31; b 6f; 5:; stbx 27,29,31; 6:; addi 31,31,1; cmplwi 31,15; ble 0b; mr 3,23; addi 4,1,8; bl _s801998A4_2; lwz 0,0x54(1); mtspr 8,0; lmw 23,0x2c(1); addi 1,1,80"
extern "C" void _s801998A4_0();
extern "C" void _s801998A4_1();
extern "C" void _s801998A4_2();
extern "C" void f_801998A4() {}
