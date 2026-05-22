// 0x801EEFB4 INVTarget::GetLocalizable(char (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8208(1); mfspr 0,8; stmw 30,0x2008(1); stw 0,0x2014(1); mr 30,4; li 0,0; lbz 9,0x0(30); mr 31,3; sth 0,0x8(1); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 30,30,1; 0:; lis 3,-32704; mr 4,30; addi 3,3,-26212; bl _s801EEFB4_0; cmpwi 3,0; bne 1f; mr 3,31; addi 4,1,8; bl _s801EEFB4_1; b 7f; 1:; lis 3,-32704; mr 4,30; addi 3,3,-26196; bl _s801EEFB4_2; cmpwi 3,0; bne 2f; mr 3,31; addi 4,1,8; bl _s801EEFB4_3; b 7f; 2:; lis 3,-32704; mr 4,30; addi 3,3,-26172; bl _s801EEFB4_4; cmpwi 3,0; bne 3f; mr 3,31; addi 4,1,8; bl _s801EEFB4_5; b 7f; 3:; lis 3,-32704; mr 4,30; addi 3,3,-26144; bl _s801EEFB4_6; cmpwi 3,0; bne 4f; mr 3,31; addi 4,1,8; bl _s801EEFB4_7; b 7f; 4:; lis 3,-32704; mr 4,30; addi 3,3,-26124; bl _s801EEFB4_8; cmpwi 3,0; bne 5f; mr 3,31; addi 4,1,8; bl _s801EEFB4_9; b 7f; 5:; lis 3,-32704; mr 4,30; addi 3,3,-26108; bl _s801EEFB4_10; cmpwi 3,0; bne 6f; mr 3,31; addi 4,1,8; bl _s801EEFB4_11; b 7f; 6:; lis 3,-32704; mr 4,30; addi 3,3,-26092; bl _s801EEFB4_12; cmpwi 3,0; bne 7f; mr 3,31; addi 4,1,8; bl _s801EEFB4_13; 7:; addi 3,1,8; bl _s801EEFB4_14; addi 3,1,8; bl _s801EEFB4_15; addi 3,1,8; bl _s801EEFB4_16; addi 3,1,8; bl _s801EEFB4_17; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801EEFB4_18; mr 30,3; addi 4,1,8; bl _s801EEFB4_19; mr 3,30; lwz 0,0x2014(1); mtspr 8,0; lmw 30,0x2008(1); addi 1,1,8208"
extern "C" void _s801EEFB4_0();
extern "C" void _s801EEFB4_1();
extern "C" void _s801EEFB4_2();
extern "C" void _s801EEFB4_3();
extern "C" void _s801EEFB4_4();
extern "C" void _s801EEFB4_5();
extern "C" void _s801EEFB4_6();
extern "C" void _s801EEFB4_7();
extern "C" void _s801EEFB4_8();
extern "C" void _s801EEFB4_9();
extern "C" void _s801EEFB4_10();
extern "C" void _s801EEFB4_11();
extern "C" void _s801EEFB4_12();
extern "C" void _s801EEFB4_13();
extern "C" void _s801EEFB4_14();
extern "C" void _s801EEFB4_15();
extern "C" void _s801EEFB4_16();
extern "C" void _s801EEFB4_17();
extern "C" void _s801EEFB4_18();
extern "C" void _s801EEFB4_19();
extern "C" void f_801EEFB4() {}
