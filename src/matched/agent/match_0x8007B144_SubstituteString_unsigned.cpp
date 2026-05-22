// 0x8007B144 SubstituteString(unsigned (504 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 23,0x14(1); stw 0,0x3c(1); mr 26,4; mr 28,6; mr 4,3; mr 23,5; addi 3,1,8; bl _s8007B144_0; addi 3,1,8; bl _s8007B144_1; mr 24,3; mr 3,26; bl _s8007B144_2; mr 25,3; li 4,0; li 5,-1; mr 3,28; bl _s8007B144_3; addi 3,13,-24836; bl _s8007B144_4; mr 4,3; li 5,0; addi 3,1,8; bl _s8007B144_5; rlwinm 31,3,0,16,31; addi 3,13,-24832; bl _s8007B144_6; mr 4,3; li 5,0; addi 3,1,8; bl _s8007B144_7; li 0,0; rlwinm 30,3,0,16,31; ori 0,0,65535; cmpw 31,0; beq 4f; cmpw 30,0; beq 4f; cmplw 30,31; ble 4f; subf 9,31,30; li 27,0; addi 9,9,-1; rlwinm 29,9,0,16,31; 0:; cmpwi 29,0; beq 3f; cmpw 29,25; bne 3f; addi 4,31,1; addi 3,1,8; bl _s8007B144_8; mr 4,26; mr 5,29; bl _s8007B144_9; cmpwi 3,0; bne 3f; cmpwi 31,0; beq 1f; addi 3,1,8; bl _s8007B144_10; mr 4,3; mr 5,31; mr 3,28; bl _s8007B144_11; 1:; mr 4,23; mr 3,28; bl _s8007B144_12; addi 4,30,1; cmpw 4,24; bge 2f; addi 3,1,8; bl _s8007B144_13; mr 4,3; mr 3,28; bl _s8007B144_14; 2:; li 27,1; b 6f; 3:; addi 3,13,-24836; addi 30,30,1; bl _s8007B144_15; mr 4,3; mr 5,30; addi 3,1,8; bl _s8007B144_16; rlwinm 31,3,0,16,31; addi 3,13,-24832; bl _s8007B144_17; mr 4,3; mr 5,30; addi 3,1,8; bl _s8007B144_18; li 0,0; rlwinm 30,3,0,16,31; ori 0,0,65535; cmpw 31,0; beq 4f; cmpw 30,0; bne 5f; 4:; addi 3,1,8; bl _s8007B144_19; mr 4,3; mr 3,28; bl _s8007B144_20; addi 3,1,8; li 4,2; bl _s8007B144_21; li 3,0; b 7f; 5:; cmplw 30,31; ble 4b; subf 9,31,30; addi 9,9,-1; rlwinm 29,9,0,16,31; 6:; cmpwi 27,0; beq 0b; addi 3,1,8; li 4,2; bl _s8007B144_22; li 3,1; 7:; lwz 0,0x3c(1); mtspr 8,0; lmw 23,0x14(1); addi 1,1,56"
extern "C" void _s8007B144_0();
extern "C" void _s8007B144_1();
extern "C" void _s8007B144_2();
extern "C" void _s8007B144_3();
extern "C" void _s8007B144_4();
extern "C" void _s8007B144_5();
extern "C" void _s8007B144_6();
extern "C" void _s8007B144_7();
extern "C" void _s8007B144_8();
extern "C" void _s8007B144_9();
extern "C" void _s8007B144_10();
extern "C" void _s8007B144_11();
extern "C" void _s8007B144_12();
extern "C" void _s8007B144_13();
extern "C" void _s8007B144_14();
extern "C" void _s8007B144_15();
extern "C" void _s8007B144_16();
extern "C" void _s8007B144_17();
extern "C" void _s8007B144_18();
extern "C" void _s8007B144_19();
extern "C" void _s8007B144_20();
extern "C" void _s8007B144_21();
extern "C" void _s8007B144_22();
extern "C" void f_8007B144() {}
