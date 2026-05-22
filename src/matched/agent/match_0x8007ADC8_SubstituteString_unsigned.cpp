// 0x8007ADC8 SubstituteString(unsigned (552 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-568(1); mfspr 0,8; stmw 23,0x214(1); stw 0,0x23c(1); addi 29,1,8; mr 30,3; mr 26,4; mr 23,5; mr 28,6; addi 4,29,8; li 5,256; mr 3,29; bl _s8007ADC8_0; mr 4,30; li 5,-1; mr 3,29; bl _s8007ADC8_1; mr 3,29; bl _s8007ADC8_2; mr 24,3; mr 3,26; bl _s8007ADC8_3; mr 25,3; mr 3,28; bl _s8007ADC8_4; addi 3,13,-24836; bl _s8007ADC8_5; mr 4,3; li 5,0; mr 3,29; bl _s8007ADC8_6; rlwinm 31,3,0,16,31; addi 3,13,-24832; bl _s8007ADC8_7; mr 4,3; li 5,0; mr 3,29; bl _s8007ADC8_8; li 0,0; rlwinm 30,3,0,16,31; ori 0,0,65535; cmpw 31,0; beq 0f; cmpw 30,0; bne 1f; 0:; mr 3,28; bl _s8007ADC8_9; mr 3,29; b 8f; 1:; cmplw 30,31; bgt 2f; mr 3,28; bl _s8007ADC8_10; mr 3,29; b 8f; 2:; subf 9,31,30; li 27,0; addi 9,9,-1; rlwinm 29,9,0,16,31; 3:; cmpwi 29,0; beq 6f; cmpw 29,25; bne 6f; addi 4,31,1; addi 3,1,8; bl _s8007ADC8_11; mr 4,26; mr 5,29; bl _s8007ADC8_12; cmpwi 3,0; bne 6f; cmpwi 31,0; beq 4f; addi 3,1,8; bl _s8007ADC8_13; mr 4,3; mr 5,31; mr 3,28; bl _s8007ADC8_14; 4:; mr 4,23; mr 3,28; li 5,-1; bl _s8007ADC8_15; addi 4,30,1; cmpw 4,24; bge 5f; addi 3,1,8; bl _s8007ADC8_16; mr 4,3; li 5,-1; mr 3,28; bl _s8007ADC8_17; 5:; li 27,1; b 10f; 6:; addi 3,13,-24836; addi 30,30,1; bl _s8007ADC8_18; mr 4,3; mr 5,30; addi 3,1,8; bl _s8007ADC8_19; rlwinm 31,3,0,16,31; addi 3,13,-24832; bl _s8007ADC8_20; mr 4,3; mr 5,30; addi 3,1,8; bl _s8007ADC8_21; li 0,0; rlwinm 30,3,0,16,31; ori 0,0,65535; cmpw 31,0; beq 7f; cmpw 30,0; bne 9f; 7:; mr 3,28; bl _s8007ADC8_22; addi 3,1,8; 8:; bl _s8007ADC8_23; mr 4,3; li 5,-1; mr 3,28; bl _s8007ADC8_24; li 3,0; b 11f; 9:; cmplw 30,31; ble 7b; subf 9,31,30; addi 9,9,-1; rlwinm 29,9,0,16,31; 10:; cmpwi 27,0; beq 3b; li 3,1; 11:; lwz 0,0x23c(1); mtspr 8,0; lmw 23,0x214(1); addi 1,1,568"
extern "C" void _s8007ADC8_0();
extern "C" void _s8007ADC8_1();
extern "C" void _s8007ADC8_2();
extern "C" void _s8007ADC8_3();
extern "C" void _s8007ADC8_4();
extern "C" void _s8007ADC8_5();
extern "C" void _s8007ADC8_6();
extern "C" void _s8007ADC8_7();
extern "C" void _s8007ADC8_8();
extern "C" void _s8007ADC8_9();
extern "C" void _s8007ADC8_10();
extern "C" void _s8007ADC8_11();
extern "C" void _s8007ADC8_12();
extern "C" void _s8007ADC8_13();
extern "C" void _s8007ADC8_14();
extern "C" void _s8007ADC8_15();
extern "C" void _s8007ADC8_16();
extern "C" void _s8007ADC8_17();
extern "C" void _s8007ADC8_18();
extern "C" void _s8007ADC8_19();
extern "C" void _s8007ADC8_20();
extern "C" void _s8007ADC8_21();
extern "C" void _s8007ADC8_22();
extern "C" void _s8007ADC8_23();
extern "C" void _s8007ADC8_24();
extern "C" void f_8007ADC8() {}
