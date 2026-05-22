// 0x801D7A50 PCTTarget::WallManipulatorCallback(InteractorModule::Interactor::CallbackData (604 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 29,3; mr. 28,4; beq 11f; lwz 30,0x0(28); cmpwi 30,3; beq 1f; bgt 0f; cmpwi 30,0; beq 3f; b 11f; 0:; cmpwi 30,4; beq 2f; cmpwi 30,5; beq 7f; b 11f; 1:; bl _s801D7A50_0; lwz 4,0x84(29); bl _s801D7A50_1; li 4,1; mr 3,29; bl _s801D7A50_2; lis 3,30424; ori 3,3,7210; bl _s801D7A50_3; b 6f; 2:; li 4,0; li 5,0; mr 3,29; bl _s801D7A50_4; b 6f; 3:; mr 4,28; mr 3,29; bl _s801D7A50_5; lwz 0,0xe8(29); mr 31,3; cmpwi 0,0; beq 4f; li 3,0; bl _s801D7A50_6; subf 4,31,3; li 3,0; bl _s801D7A50_7; lis 3,-30726; ori 3,3,3858; bl _s801D7A50_8; lhz 11,-21224(13); addi 9,1,8; sth 30,0x8(1); mr 4,9; lhz 0,-21200(13); li 5,0; sth 11,0x4(9); sth 11,0x2(9); sth 0,0x8(1); lwz 11,-21476(13); lwz 9,0x0(11); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,11,3; mtspr 8,0; blrl; b 5f; 4:; xoris 0,31,32768; stw 0,0x14(1); lis 11,17200; lis 10,-32705; mr 8,9; stw 11,0x10(1); li 3,0; lfd f13,0x48a0(10); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fmr f13,f0; fctiwz f12,f13; stfd f12,0x10(1); lwz 31,0x14(1); bl _s801D7A50_9; add 4,3,31; li 3,0; bl _s801D7A50_10; lis 3,30194; ori 3,3,56718; bl _s801D7A50_11; 5:; mr 3,29; bl _s801D7A50_12; lwz 0,0x214(29); stw 3,0x20c(29); cmpwi 0,0; beq 6f; mr 3,0; li 4,0; bl _s801D7A50_13; lwz 3,0x214(29); li 4,0; bl _s801D7A50_14; 6:; li 3,0; crxor 6,6,6; bl _s801D7A50_15; li 3,1; b 12f; 7:; mr 3,29; mr 4,28; bl _s801D7A50_16; lwz 0,0xe8(29); mr 31,3; cmpwi 0,0; bne 8f; xoris 0,31,32768; stw 0,0x14(1); lis 11,17200; lis 10,-32705; mr 8,9; stw 11,0x10(1); lfd f13,0x48a0(10); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fmr f13,f0; fctiwz f12,f13; stfd f12,0x10(1); lwz 31,0x14(1); 8:; lwz 3,0x214(29); cmpwi 3,0; beq 10f; mr 4,31; bl _s801D7A50_17; lwz 3,0x214(29); li 4,1; cmpwi 31,0; bne 9f; li 4,0; 9:; bl _s801D7A50_18; 10:; lwz 4,0x10(28); lis 3,-32705; addi 3,3,18552; mr 5,31; crxor 6,6,6; bl _s801D7A50_19; li 3,1; b 12f; 11:; li 3,0; 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s801D7A50_0();
extern "C" void _s801D7A50_1();
extern "C" void _s801D7A50_2();
extern "C" void _s801D7A50_3();
extern "C" void _s801D7A50_4();
extern "C" void _s801D7A50_5();
extern "C" void _s801D7A50_6();
extern "C" void _s801D7A50_7();
extern "C" void _s801D7A50_8();
extern "C" void _s801D7A50_9();
extern "C" void _s801D7A50_10();
extern "C" void _s801D7A50_11();
extern "C" void _s801D7A50_12();
extern "C" void _s801D7A50_13();
extern "C" void _s801D7A50_14();
extern "C" void _s801D7A50_15();
extern "C" void _s801D7A50_16();
extern "C" void _s801D7A50_17();
extern "C" void _s801D7A50_18();
extern "C" void _s801D7A50_19();
extern "C" void f_801D7A50() {}
