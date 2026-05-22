// 0x8012FE1C cXPortalImpl::ApplyWallStyle(bool) (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stmw 26,0x80(1); stw 0,0x9c(1); lwz 11,0x0(3); lwz 29,-21488(13); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; mr. 27,3; beq 4f; addi 26,1,72; 0:; lwz 9,0x0(27); li 4,6; lwz 3,0x0(9); bl _s8012FE1C_0; mr 30,3; lwz 9,0x4(30); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; lwz 9,0x0(30); lwz 10,0x0(9); lwz 11,0x4(10); lha 3,0x2a0(11); lwz 0,0x2a4(11); add 3,10,3; mtspr 8,0; blrl; mr. 28,3; beq 3f; lwz 11,0x0(30); addi 3,1,8; lwz 10,0x0(11); lwz 9,0x4(10); lwz 0,0x35c(9); lha 4,0x358(9); mtspr 8,0; add 4,10,4; blrl; lwz 9,0x0(29); addi 4,1,8; lha 3,0x58(9); lwz 0,0x5c(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; lwz 9,0x0(29); addi 31,1,16; mr 3,31; addi 5,1,8; lha 4,0xa8(9); lwz 0,0xac(9); add 4,29,4; mtspr 8,0; blrl; mr 3,31; mr 4,28; bl _s8012FE1C_1; cmpwi 3,0; beq 1f; lwz 9,0x4(30); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; mr 4,3; mr 5,28; mr 3,31; bl _s8012FE1C_2; mr 4,31; mr 3,26; bl _s8012FE1C_3; lwz 9,0x0(29); addi 4,1,8; mr 5,26; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,29,3; mtspr 8,0; blrl; 1:; mr 3,31; li 4,2; bl _s8012FE1C_4; 2:; addi 3,1,8; li 4,2; bl _s8012FE1C_5; 3:; lwz 9,0x4(27); lha 3,0x18(9); lwz 0,0x1c(9); add 3,27,3; mtspr 8,0; blrl; mr. 27,3; bne 0b; 4:; lwz 0,0x9c(1); mtspr 8,0; lmw 26,0x80(1); addi 1,1,152"
extern "C" void _s8012FE1C_0();
extern "C" void _s8012FE1C_1();
extern "C" void _s8012FE1C_2();
extern "C" void _s8012FE1C_3();
extern "C" void _s8012FE1C_4();
extern "C" void _s8012FE1C_5();
extern "C" void f_8012FE1C() {}
