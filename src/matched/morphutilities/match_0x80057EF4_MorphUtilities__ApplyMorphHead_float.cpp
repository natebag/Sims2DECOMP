// 0x80057EF4 MorphUtilities::ApplyMorphHead(float) (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 30,3; fmr f31,f1; li 4,0; li 5,0; bl _s80057EF4_0; mr 3,30; li 4,2; fmr f1,f31; li 5,0; bl _s80057EF4_1; mr 3,30; li 4,3; fmr f1,f31; li 5,0; bl _s80057EF4_2; mr 3,30; li 4,4; fmr f1,f31; li 5,0; bl _s80057EF4_3; mr 3,30; li 4,5; fmr f1,f31; li 5,0; bl _s80057EF4_4; mr 3,30; li 4,6; fmr f1,f31; li 5,0; bl _s80057EF4_5; mr 3,30; li 4,18; fmr f1,f31; li 5,0; bl _s80057EF4_6; mr 3,30; li 4,19; fmr f1,f31; li 5,0; bl _s80057EF4_7; mr 3,30; li 4,1; fmr f1,f31; li 5,0; bl _s80057EF4_8; mr 3,30; li 4,7; fmr f1,f31; li 5,0; bl _s80057EF4_9; mr 3,30; li 4,9; fmr f1,f31; li 5,0; bl _s80057EF4_10; mr 3,30; li 4,20; fmr f1,f31; li 5,0; bl _s80057EF4_11; mr 3,30; fmr f1,f31; li 4,24; li 5,0; bl _s80057EF4_12; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"

extern "C" void _s80057EF4_0();
extern "C" void _s80057EF4_1();
extern "C" void _s80057EF4_2();
extern "C" void _s80057EF4_3();
extern "C" void _s80057EF4_4();
extern "C" void _s80057EF4_5();
extern "C" void _s80057EF4_6();
extern "C" void _s80057EF4_7();
extern "C" void _s80057EF4_8();
extern "C" void _s80057EF4_9();
extern "C" void _s80057EF4_10();
extern "C" void _s80057EF4_11();
extern "C" void _s80057EF4_12();

struct MorphUtilities {
    void ApplyMorphHead();
};

void MorphUtilities::ApplyMorphHead() {
}
