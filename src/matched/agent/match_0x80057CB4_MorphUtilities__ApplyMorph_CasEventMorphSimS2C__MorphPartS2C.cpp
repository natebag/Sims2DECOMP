// 0x80057CB4 MorphUtilities::ApplyMorph(CasEventMorphSimS2C::MorphPartS2C, (576 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; cmpwi 4,1; fmr f31,f1; beq 2f; bgt 0f; cmpwi 4,0; beq 1f; b 4f; 0:; cmpwi 4,3; beq 3f; b 4f; 1:; li 4,1; fmr f1,f31; li 5,1; mr 3,31; bl _s80057CB4_0; li 4,7; fmr f1,f31; li 5,1; mr 3,31; bl _s80057CB4_1; li 4,9; fmr f1,f31; li 5,1; mr 3,31; bl _s80057CB4_2; li 4,12; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_3; li 4,20; fmr f1,f31; li 5,1; mr 3,31; bl _s80057CB4_4; li 4,24; fmr f1,f31; li 5,1; mr 3,31; bl _s80057CB4_5; li 4,10; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_6; li 4,13; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_7; li 4,22; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_8; li 4,23; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_9; li 4,25; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_10; mr 3,31; fmr f1,f31; li 4,15; li 5,0; bl _s80057CB4_11; b 4f; 2:; li 4,8; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_12; li 4,11; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_13; li 4,14; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_14; li 4,21; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_15; li 4,8; fmr f1,f31; li 5,1; mr 3,31; bl _s80057CB4_16; li 4,11; fmr f1,f31; li 5,1; mr 3,31; bl _s80057CB4_17; li 4,14; fmr f1,f31; li 5,1; mr 3,31; bl _s80057CB4_18; mr 3,31; fmr f1,f31; li 4,21; li 5,1; bl _s80057CB4_19; b 4f; 3:; li 4,15; fmr f1,f31; li 5,1; mr 3,31; bl _s80057CB4_20; li 4,15; fmr f1,f31; li 5,1; mr 3,31; bl _s80057CB4_21; li 4,17; fmr f1,f31; li 5,0; mr 3,31; bl _s80057CB4_22; mr 3,31; fmr f1,f31; li 4,17; li 5,0; bl _s80057CB4_23; 4:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s80057CB4_0();
extern "C" void _s80057CB4_1();
extern "C" void _s80057CB4_2();
extern "C" void _s80057CB4_3();
extern "C" void _s80057CB4_4();
extern "C" void _s80057CB4_5();
extern "C" void _s80057CB4_6();
extern "C" void _s80057CB4_7();
extern "C" void _s80057CB4_8();
extern "C" void _s80057CB4_9();
extern "C" void _s80057CB4_10();
extern "C" void _s80057CB4_11();
extern "C" void _s80057CB4_12();
extern "C" void _s80057CB4_13();
extern "C" void _s80057CB4_14();
extern "C" void _s80057CB4_15();
extern "C" void _s80057CB4_16();
extern "C" void _s80057CB4_17();
extern "C" void _s80057CB4_18();
extern "C" void _s80057CB4_19();
extern "C" void _s80057CB4_20();
extern "C" void _s80057CB4_21();
extern "C" void _s80057CB4_22();
extern "C" void _s80057CB4_23();
extern "C" void f_80057CB4() {}
