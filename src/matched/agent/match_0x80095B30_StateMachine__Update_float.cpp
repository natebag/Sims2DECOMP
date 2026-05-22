// 0x80095B30 StateMachine::Update(float) (472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f30,0x28(1); stfd f31,0x30(1); stmw 25,0xc(1); stw 0,0x3c(1); mr 31,3; fmr f31,f1; lwz 0,0x94(31); cmpwi 0,0; beq 6f; lwz 0,0x24(31); cmpwi 0,0; bne 6f; addi 3,31,60; stfs f31,0x28(31); mr 26,3; bl _s80095B30_0; li 25,0; lwz 0,0x84(31); cmpwi 0,0; beq 1f; li 27,0; mr 28,26; li 25,1; 0:; lwz 29,0x84(31); mr 3,31; stw 27,0x84(31); lwz 30,0x3c(31); bl _s80095B30_1; mr 3,28; bl _s80095B30_2; stw 30,0xc(28); mr 3,31; li 4,0; bl _s80095B30_3; mr 4,29; mr 3,31; bl _s80095B30_4; mr 3,31; li 4,0; bl _s80095B30_5; lwz 0,0x84(31); stw 27,0x90(31); cmpwi 0,0; bne 0b; 1:; lwz 0,0x88(31); cmpwi 0,0; beq 2f; lwz 30,0x3c(31); mr 3,26; bl _s80095B30_6; mr 3,31; bl _s80095B30_7; lwz 9,0x8c(31); li 0,0; stw 30,0x44(31); stw 0,0x88(31); stw 9,0x90(31); 2:; mr 3,26; fmr f1,f31; bl _s80095B30_8; lwz 30,0x40(31); cmpwi 30,0; beq 4f; lis 9,-32706; lfs f0,0x4c(31); lfs f13,-30556(9); fcmpu 0,f0,f13; bne 4f; fmr f30,f13; li 29,0; li 25,1; 3:; stw 29,0x40(31); mr 3,31; li 4,0; bl _s80095B30_9; mr 4,30; mr 3,26; bl _s80095B30_10; mr 3,31; li 4,0; bl _s80095B30_11; lwz 30,0x40(31); cmpwi 30,0; beq 4f; lfs f0,0x4c(31); fcmpu 0,f0,f30; beq 3b; 4:; cmpwi 25,0; beq 5f; li 4,1; mr 3,31; bl _s80095B30_12; lwz 11,0x3c(31); lwz 9,0x18(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; mr 3,31; li 4,0; bl _s80095B30_13; lwz 9,0x3c(31); lwz 0,0x14(9); cmpwi 0,0; beq 6f; 5:; mr 3,26; fmr f1,f31; bl _s80095B30_14; 6:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0xc(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s80095B30_0();
extern "C" void _s80095B30_1();
extern "C" void _s80095B30_2();
extern "C" void _s80095B30_3();
extern "C" void _s80095B30_4();
extern "C" void _s80095B30_5();
extern "C" void _s80095B30_6();
extern "C" void _s80095B30_7();
extern "C" void _s80095B30_8();
extern "C" void _s80095B30_9();
extern "C" void _s80095B30_10();
extern "C" void _s80095B30_11();
extern "C" void _s80095B30_12();
extern "C" void _s80095B30_13();
extern "C" void _s80095B30_14();
extern "C" void f_80095B30() {}
