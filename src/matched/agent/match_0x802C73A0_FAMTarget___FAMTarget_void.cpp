// 0x802C73A0 FAMTarget::~FAMTarget(void) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bl _s802C73A0_0; mr 0,3; mr 4,30; mr 3,28; mr 5,29; mr 6,0; stw 0,0x4(28); bl _s802C73A0_1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24; blr; mr. 6,6; beqlr; addic. 9,5,-1; bltlr; mullw 0,9,4; neg 4,4; mr 10,0; add 11,0,6; 0:; lwz 0,0x0(3); addic. 9,9,-1; stwx 0,10,6; stw 11,0x0(3); add 10,10,4; add 11,11,4; bge 0b; blr; stw 5,0x4(3); li 0,0; stw 4,0x0(3); stb 0,0x0(4); blr; stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; mr 28,5; mr. 29,4; bne 1f; lwz 29,-26884(13); 1:; mr 3,29; bl _s802C73A0_2; mr 27,3; cmpwi 28,0; bne 2f; lwz 28,-26884(13); 2:; mr 3,28; bl _s802C73A0_3; lwz 31,0x4(30); mr 26,3; cmpw 31,27; ble 3f; mr 31,27; 3:; cmpwi 31,0; beq 4f; lwz 3,0x0(30); mr 4,29; mr 5,31; crxor 6,6,6; bl _s802C73A0_4; 4:; lwz 9,0x4(30); addi 3,26,1; subf 9,31,9; addi 5,9,-1; cmpw 5,3; ble 5f; mr 5,3; 5:; cmpwi 5,0; ble 6f; lwz 3,0x0(30); mr 4,28; add 3,3,31; crxor 6,6,6; bl _s802C73A0_5; 6:; lwz 9,0x4(30); li 11,0; lwz 0,0x0(30); mr 3,30; add 9,9,0; stb 11,-1(9); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802C73A0_0();
extern "C" void _s802C73A0_1();
extern "C" void _s802C73A0_2();
extern "C" void _s802C73A0_3();
extern "C" void _s802C73A0_4();
extern "C" void _s802C73A0_5();
extern "C" void f_802C73A0() {}
