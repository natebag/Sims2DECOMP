// 0x802C798C EFixedString::operator+=(char (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; bl _s802C798C_0; mr 30,3; mr 3,29; bl _s802C798C_1; lwz 9,0x4(31); addi 5,3,1; subf 9,30,9; addi 9,9,-1; cmpw 5,9; ble 0f; mr 5,9; 0:; cmpwi 5,0; ble 1f; lwz 3,0x0(31); mr 4,29; add 3,3,30; crxor 6,6,6; bl _s802C798C_2; 1:; lwz 9,0x4(31); li 11,0; lwz 0,0x0(31); mr 3,31; add 9,9,0; stb 11,-1(9); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802C798C_0();
extern "C" void _s802C798C_1();
extern "C" void _s802C798C_2();
extern "C" void f_802C798C() {}
