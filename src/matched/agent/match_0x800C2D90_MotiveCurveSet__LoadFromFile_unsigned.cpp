// 0x800C2D90 MotiveCurveSet::LoadFromFile(unsigned (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 27,3; li 30,0; stw 30,0x8(1); mr 29,4; mr 28,5; li 3,0; bl _s800C2D90_0; li 31,1; stw 30,0x8(1); bl _s800C2D90_1; stw 3,0x8(1); mr 4,29; mr 5,28; lwz 9,0x0(3); lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; mtspr 8,9; blrl; lwz 11,0x8(1); li 4,-1; lwz 9,0x0(11); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(27); cmpw 31,0; bgt 2f; li 29,0; 0:; lwz 0,0x0(27); add 30,0,29; mr 3,30; bl _s800C2D90_2; lwz 11,0x8(1); mr 4,31; li 5,-1; lwz 9,0x0(11); lha 3,0x80(9); lwz 0,0x84(9); add 3,11,3; mtspr 8,0; blrl; mr. 4,3; beq 1f; mr 3,30; bl _s800C2D90_3; 1:; lwz 0,0x4(27); addi 31,31,1; addi 29,29,20; cmpw 31,0; ble 0b; 2:; lwz 3,0x8(1); bl _s800C2D90_4; li 0,0; stw 0,0x8(1); lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800C2D90_0();
extern "C" void _s800C2D90_1();
extern "C" void _s800C2D90_2();
extern "C" void _s800C2D90_3();
extern "C" void _s800C2D90_4();
extern "C" void f_800C2D90() {}
