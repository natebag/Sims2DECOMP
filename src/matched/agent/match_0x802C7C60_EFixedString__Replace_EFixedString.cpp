// 0x802C7C60 EFixedString::Replace(EFixedString (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,5; mr 29,3; mr 30,4; mr 27,6; mr 4,28; bl _s802C7C60_0; mr 31,3; cmpwi 31,-1; li 3,0; beq 0f; mr 5,31; mr 3,29; mr 4,30; bl _s802C7C60_1; mr 4,27; mr 3,30; bl _s802C7C60_2; mr 3,28; bl _s802C7C60_3; lwz 4,0x0(29); add 0,31,3; mr 3,30; add 4,4,0; bl _s802C7C60_4; lwz 4,0x0(30); mr 3,29; bl _s802C7C60_5; li 3,1; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802C7C60_0();
extern "C" void _s802C7C60_1();
extern "C" void _s802C7C60_2();
extern "C" void _s802C7C60_3();
extern "C" void _s802C7C60_4();
extern "C" void _s802C7C60_5();
extern "C" void f_802C7C60() {}
