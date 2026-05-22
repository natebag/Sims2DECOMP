// 0x803B16B0 basic_string<char, (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); li 0,-2; mr 31,3; cmplw 4,0; stw 4,0x8(1); ble 0f; bl _s803B16B0_0; 0:; lwz 0,0x4(31); addi 8,1,12; lwz 11,0x0(31); addi 10,1,8; lwz 9,0x8(1); subf 0,11,0; cmplw 9,0; stw 0,0xc(1); bge 1f; mr 10,8; 1:; lwz 0,0x0(10); addic. 28,0,1; beq 3f; cmplwi 28,128; ble 2f; mr 3,28; bl _s803B16B0_1; mr 29,3; b 4f; 2:; mr 3,28; bl _s803B16B0_2; mr 29,3; b 4f; 3:; li 29,0; 4:; lwz 4,0x0(31); lwz 30,0x4(31); cmpw 30,4; beq 5f; subf 30,4,30; mr 3,29; mr 5,30; bl _s803B16B0_3; add 30,3,30; b 6f; 5:; mr 30,29; 6:; li 0,0; stb 0,0x0(30); lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 4,3,0; beq 8f; cmplwi 4,128; ble 7f; bl _s803B16B0_4; b 8f; 7:; bl _s803B16B0_5; 8:; add 0,29,28; stw 30,0x4(31); stw 0,0xc(31); stw 29,0x0(31); lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s803B16B0_0();
extern "C" void _s803B16B0_1();
extern "C" void _s803B16B0_2();
extern "C" void _s803B16B0_3();
extern "C" void _s803B16B0_4();
extern "C" void _s803B16B0_5();
extern "C" void f_803B16B0() {}
