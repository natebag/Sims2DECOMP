// 0x8009CCE8 BString::insert_str(unsigned (484 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 26,0x10(1); stw 0,0x2c(1); stw 12,0xc(1); mr 31,3; mr 28,4; mr 26,5; mr 27,6; bl _s8009CCE8_0; cmplw 28,3; ble 0f; bl _s8009CCE8_1; 0:; mr 3,31; bl _s8009CCE8_2; not 0,27; cmplw 3,0; blt 1f; bl _s8009CCE8_3; 1:; mr 3,31; bl _s8009CCE8_4; cmplwi 3,1; bgt 2f; mr 3,31; addi 29,27,1; bl _s8009CCE8_5; mr 30,3; mr 3,31; bl _s8009CCE8_6; subf 30,3,30; cmplw 29,30; ble 3f; 2:; bl _s8009CCE8_7; cmpwi 4,27,0; li 4,16; li 5,0; bl _s8009CCE8_8; mr 29,3; mr 3,31; bl _s8009CCE8_9; mr 30,3; mr 3,31; bl _s8009CCE8_10; add 6,3,27; mr 4,30; mr 5,28; mr 3,29; bl _s8009CCE8_11; mr 29,3; mr 3,31; bl _s8009CCE8_12; mr 30,3; mr 3,31; bl _s8009CCE8_13; lwz 0,0x0(29); subf 5,28,3; add 4,30,28; add 0,0,28; add 3,0,27; bl _s8009CCE8_14; mr 3,31; bl _s8009CCE8_15; mr 30,3; bl _s8009CCE8_16; lwz 9,0x0(29); add 9,9,30; stbx 3,9,27; mr 3,31; bl _s8009CCE8_17; stw 3,0x4(29); mr 3,31; bl _s8009CCE8_18; stw 29,0x0(31); b 6f; 3:; mr 3,31; cmpwi 4,27,0; bl _s8009CCE8_19; subf. 29,28,3; beq 5f; 4:; mr 3,31; bl _s8009CCE8_20; mr 30,3; mr 3,31; bl _s8009CCE8_21; add 3,3,28; add 30,30,28; add 3,3,29; add 30,30,27; lbz 0,-1(3); add 30,30,29; addic. 29,29,-1; stb 0,-1(30); bne 4b; 5:; mr 3,31; bl _s8009CCE8_22; mr 30,3; mr 3,31; bl _s8009CCE8_23; mr 29,3; bl _s8009CCE8_24; add 30,30,29; stbx 3,30,27; 6:; beq cr4,7f; mr 3,31; bl _s8009CCE8_25; add 3,3,28; mr 4,26; mr 5,27; bl _s8009CCE8_26; 7:; lwz 9,0x0(31); lwz 0,0x4(9); add 0,0,27; stw 0,0x4(9); lwz 0,0x2c(1); lwz 12,0xc(1); mtspr 8,0; lmw 26,0x10(1); mtcrf 8,12; addi 1,1,40"
extern "C" void _s8009CCE8_0();
extern "C" void _s8009CCE8_1();
extern "C" void _s8009CCE8_2();
extern "C" void _s8009CCE8_3();
extern "C" void _s8009CCE8_4();
extern "C" void _s8009CCE8_5();
extern "C" void _s8009CCE8_6();
extern "C" void _s8009CCE8_7();
extern "C" void _s8009CCE8_8();
extern "C" void _s8009CCE8_9();
extern "C" void _s8009CCE8_10();
extern "C" void _s8009CCE8_11();
extern "C" void _s8009CCE8_12();
extern "C" void _s8009CCE8_13();
extern "C" void _s8009CCE8_14();
extern "C" void _s8009CCE8_15();
extern "C" void _s8009CCE8_16();
extern "C" void _s8009CCE8_17();
extern "C" void _s8009CCE8_18();
extern "C" void _s8009CCE8_19();
extern "C" void _s8009CCE8_20();
extern "C" void _s8009CCE8_21();
extern "C" void _s8009CCE8_22();
extern "C" void _s8009CCE8_23();
extern "C" void _s8009CCE8_24();
extern "C" void _s8009CCE8_25();
extern "C" void _s8009CCE8_26();
extern "C" void f_8009CCE8() {}
