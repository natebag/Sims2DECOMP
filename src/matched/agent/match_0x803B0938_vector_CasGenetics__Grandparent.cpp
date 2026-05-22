// 0x803B0938 vector<CasGenetics::Grandparent (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,3; lwz 29,0x0(28); lwz 0,0xc(28); subf 0,29,0; srawi 0,0,2; cmplw 0,4; bge 10f; lwz 27,0x4(28); cmpwi 29,0; subf 0,29,27; srawi 26,0,2; beq 5f; cmpwi 4,0; beq 1f; rlwinm 0,4,2,0,29; mr 30,0; cmplwi 0,128; ble 0f; mr 3,30; bl _s803B0938_0; mr 31,3; b 2f; 0:; mr 3,30; bl _s803B0938_1; mr 31,3; b 2f; 1:; li 31,0; li 30,0; 2:; cmpw 27,29; beq 3f; mr 4,29; mr 3,31; subf 5,4,27; bl _s803B0938_2; 3:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 9f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 4f; bl _s803B0938_3; b 9f; 4:; bl _s803B0938_4; b 9f; 5:; cmpwi 4,0; beq 7f; rlwinm 0,4,2,0,29; mr 30,0; cmplwi 0,128; ble 6f; mr 3,30; bl _s803B0938_5; b 8f; 6:; mr 3,30; bl _s803B0938_6; b 8f; 7:; li 3,0; li 30,0; 8:; mr 31,3; 9:; rlwinm 0,26,2,0,29; add 9,30,31; add 0,0,31; stw 9,0xc(28); stw 31,0x0(28); stw 0,0x4(28); 10:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s803B0938_0();
extern "C" void _s803B0938_1();
extern "C" void _s803B0938_2();
extern "C" void _s803B0938_3();
extern "C" void _s803B0938_4();
extern "C" void _s803B0938_5();
extern "C" void _s803B0938_6();
extern "C" void f_803B0938() {}
