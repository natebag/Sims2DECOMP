// 0x8005C23C SAnimator2::~SAnimator2(void) (512 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; lis 9,-32698; lwz 0,0x28(31); addi 9,9,-13744; mr 25,4; stw 9,0x0(31); cmpwi 0,0; beq 0f; lis 3,-32693; mr 4,0; addi 3,3,11064; bl _s8005C23C_0; lwz 9,-32344(13); li 0,0; stw 0,0x28(31); addi 9,9,-1; stw 9,-32344(13); 0:; mr 3,31; addi 29,31,1488; bl _s8005C23C_1; addi 30,31,1500; mr 3,31; mr 27,29; bl _s8005C23C_2; mr 28,30; mr 4,29; mr 3,31; bl _s8005C23C_3; addi 29,31,1568; mr 4,30; mr 3,31; bl _s8005C23C_4; addi 30,31,360; mr 3,31; addi 26,31,220; bl _s8005C23C_5; mr 3,31; bl _s8005C23C_6; mr 3,31; bl _s8005C23C_7; mr 3,31; bl _s8005C23C_8; lwz 0,0x604(31); cmpwi 0,0; beq 4f; lwz 11,0x4(31); cmpwi 11,0; beq 2f; lwz 9,0x4(11); lha 3,0x150(9); lwz 0,0x154(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 2f; lwz 9,0x604(31); li 11,288; 1:; lwz 0,0x0(9); addic. 11,11,-24; stw 0,0x0(3); lwz 0,0x4(9); stw 0,0x4(3); lwz 0,0x8(9); stw 0,0x8(3); lwz 0,0xc(9); stw 0,0xc(3); lwz 0,0x10(9); stw 0,0x10(3); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(3); addi 3,3,24; bne 1b; lwz 0,0x0(9); stw 0,0x0(3); 2:; lwz 3,0x604(31); cmpwi 3,0; beq 3f; bl _s8005C23C_9; 3:; li 0,0; stw 0,0x604(31); 4:; li 4,2; mr 3,29; bl _s8005C23C_10; mr 3,28; bl _s8005C23C_11; mr 3,27; bl _s8005C23C_12; lwz 3,0x168(31); cmpwi 3,0; beq 6f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 5f; bl _s8005C23C_13; b 6f; 5:; bl _s8005C23C_14; 6:; lwz 3,0xdc(31); cmpwi 3,0; beq 8f; lwz 0,0xc(26); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 7f; bl _s8005C23C_15; b 8f; 7:; bl _s8005C23C_16; 8:; lis 9,-32698; andi. 0,25,1; addi 9,9,-13392; stw 9,0x0(31); beq 9f; bl _s8005C23C_17; mr 4,31; bl _s8005C23C_18; 9:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8005C23C_0();
extern "C" void _s8005C23C_1();
extern "C" void _s8005C23C_2();
extern "C" void _s8005C23C_3();
extern "C" void _s8005C23C_4();
extern "C" void _s8005C23C_5();
extern "C" void _s8005C23C_6();
extern "C" void _s8005C23C_7();
extern "C" void _s8005C23C_8();
extern "C" void _s8005C23C_9();
extern "C" void _s8005C23C_10();
extern "C" void _s8005C23C_11();
extern "C" void _s8005C23C_12();
extern "C" void _s8005C23C_13();
extern "C" void _s8005C23C_14();
extern "C" void _s8005C23C_15();
extern "C" void _s8005C23C_16();
extern "C" void _s8005C23C_17();
extern "C" void _s8005C23C_18();
extern "C" void f_8005C23C() {}
