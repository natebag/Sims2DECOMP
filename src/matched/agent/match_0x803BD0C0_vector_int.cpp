// 0x803BD0C0 vector<int, (640 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 28,3; mr 29,4; mr 26,6; mr. 5,5; beq 21f; lwz 0,0xc(28); lwz 3,0x4(28); subf 0,3,0; srawi 0,0,2; cmplw 0,5; blt 8f; mr 31,3; lwz 9,0x0(26); subf 0,29,31; srawi 0,0,2; stw 9,0x8(1); cmplw 0,5; ble 3f; rlwinm 0,5,2,0,29; subf 30,0,31; mr 27,0; cmpw 31,30; beq 0f; mr 4,30; subf 5,30,31; bl _s803BD0C0_0; 0:; lwz 0,0x4(28); subf. 5,29,30; add 0,0,27; stw 0,0x4(28); ble 1f; subf 3,5,31; mr 4,29; bl _s803BD0C0_1; 1:; mr 4,29; add 0,27,4; cmpw 4,0; beq 21f; lwz 9,0x8(1); 2:; stw 9,0x0(4); addi 4,4,4; cmpw 4,0; bne 2b; b 21f; 3:; subf. 9,0,5; addi 11,1,8; mtspr 9,9; cmpw cr6,29,31; mr 26,11; rlwinm 27,0,2,0,29; mr 9,31; cmpw cr7,31,29; mfspr 10,9; mfcr 30; rlwinm 30,30,24,0,3; beq 5f; 4:; lwz 0,0x0(11); stw 0,0x0(9); addi 9,9,4; bdnz 4b; 5:; lwz 9,0x4(28); rlwinm 0,10,2,0,29; add 3,9,0; stw 3,0x4(28); beq cr7,6f; mr 4,29; subf 5,29,31; bl _s803BD0C0_2; 6:; lwz 0,0x4(28); mr 4,29; mtcrf 128,30; add 0,0,27; stw 0,0x4(28); beq 21f; lwz 0,0x0(26); 7:; stw 0,0x0(4); addi 4,4,4; cmpw 4,31; bne 7b; b 21f; 8:; lwz 0,0x0(28); addi 11,1,16; stw 5,0x10(1); addi 9,1,12; subf 0,0,3; srawi 3,0,2; cmplw 3,5; stw 3,0xc(1); bge 9f; mr 9,11; 9:; lwz 0,0x0(9); add. 0,3,0; beq 11f; rlwinm 0,0,2,0,29; mr 27,0; cmplwi 0,128; ble 10f; mr 3,27; bl _s803BD0C0_3; mr 31,3; b 12f; 10:; mr 3,27; bl _s803BD0C0_4; mr 31,3; b 12f; 11:; li 31,0; li 27,0; 12:; lwz 4,0x0(28); cmpw 29,4; beq 13f; subf 30,4,29; mr 3,31; mr 5,30; bl _s803BD0C0_5; add 3,3,30; b 14f; 13:; mr 3,31; 14:; lwz 0,0x10(1); mtspr 9,0; cmpwi 0,0; beq 16f; 15:; lwz 0,0x0(26); stw 0,0x0(3); addi 3,3,4; bdnz 15b; 16:; lwz 30,0x4(28); cmpw 30,29; beq 17f; subf 30,29,30; mr 4,29; mr 5,30; bl _s803BD0C0_6; add 30,3,30; b 18f; 17:; mr 30,3; 18:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 20f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 19f; bl _s803BD0C0_7; b 20f; 19:; bl _s803BD0C0_8; 20:; add 0,27,31; stw 31,0x0(28); stw 0,0xc(28); stw 30,0x4(28); 21:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s803BD0C0_0();
extern "C" void _s803BD0C0_1();
extern "C" void _s803BD0C0_2();
extern "C" void _s803BD0C0_3();
extern "C" void _s803BD0C0_4();
extern "C" void _s803BD0C0_5();
extern "C" void _s803BD0C0_6();
extern "C" void _s803BD0C0_7();
extern "C" void _s803BD0C0_8();
extern "C" void f_803BD0C0() {}
