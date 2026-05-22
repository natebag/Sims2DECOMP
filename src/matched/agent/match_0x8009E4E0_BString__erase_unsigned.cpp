// 0x8009E4E0 BString::erase(unsigned (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 28,4; mr 30,5; bl _s8009E4E0_0; cmplw 28,3; ble 0f; bl _s8009E4E0_1; 0:; mr 3,31; bl _s8009E4E0_2; subf 3,28,3; cmplw 30,3; ble 1f; mr 3,31; bl _s8009E4E0_3; subf 27,28,3; b 2f; 1:; mr 27,30; 2:; mr 3,31; bl _s8009E4E0_4; cmplwi 3,1; ble 3f; bl _s8009E4E0_5; li 4,16; li 5,0; bl _s8009E4E0_6; mr 29,3; mr 3,31; bl _s8009E4E0_7; mr 30,3; mr 3,31; bl _s8009E4E0_8; mr 6,3; mr 4,30; mr 5,28; mr 3,29; bl _s8009E4E0_9; mr 29,3; mr 3,31; bl _s8009E4E0_10; mr 30,3; mr 3,31; bl _s8009E4E0_11; lwz 0,0x0(29); subf 5,27,3; add 30,30,28; subf 5,28,5; add 4,30,27; add 3,0,28; bl _s8009E4E0_12; mr 3,31; bl _s8009E4E0_13; subf 3,27,3; stw 3,0x4(29); mr 3,31; bl _s8009E4E0_14; stw 29,0x0(31); b 6f; 3:; mr 3,31; bl _s8009E4E0_15; cmpw 27,3; bne 4f; lwz 9,0x0(31); li 0,0; b 5f; 4:; cmpwi 27,0; beq 6f; mr 3,31; bl _s8009E4E0_16; mr 29,3; mr 3,31; bl _s8009E4E0_17; mr 30,3; mr 3,31; bl _s8009E4E0_18; subf 5,27,3; add 30,30,28; subf 5,28,5; add 3,29,28; add 4,30,27; bl _s8009E4E0_19; lwz 9,0x0(31); lwz 0,0x4(9); subf 0,27,0; 5:; stw 0,0x4(9); 6:; mr 3,31; bl _s8009E4E0_20; cmpwi 3,0; beq 7f; mr 3,31; bl _s8009E4E0_21; mr 29,3; mr 3,31; bl _s8009E4E0_22; mr 30,3; bl _s8009E4E0_23; stbx 3,29,30; 7:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009E4E0_0();
extern "C" void _s8009E4E0_1();
extern "C" void _s8009E4E0_2();
extern "C" void _s8009E4E0_3();
extern "C" void _s8009E4E0_4();
extern "C" void _s8009E4E0_5();
extern "C" void _s8009E4E0_6();
extern "C" void _s8009E4E0_7();
extern "C" void _s8009E4E0_8();
extern "C" void _s8009E4E0_9();
extern "C" void _s8009E4E0_10();
extern "C" void _s8009E4E0_11();
extern "C" void _s8009E4E0_12();
extern "C" void _s8009E4E0_13();
extern "C" void _s8009E4E0_14();
extern "C" void _s8009E4E0_15();
extern "C" void _s8009E4E0_16();
extern "C" void _s8009E4E0_17();
extern "C" void _s8009E4E0_18();
extern "C" void _s8009E4E0_19();
extern "C" void _s8009E4E0_20();
extern "C" void _s8009E4E0_21();
extern "C" void _s8009E4E0_22();
extern "C" void _s8009E4E0_23();
extern "C" void f_8009E4E0() {}
