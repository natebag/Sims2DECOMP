// 0x8009DF88 BString::assign(BString (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,4; mr 28,3; mr 29,5; mr 30,6; mr 3,31; bl _s8009DF88_0; cmplw 29,3; ble 0f; bl _s8009DF88_1; 0:; mr 3,31; bl _s8009DF88_2; subf 3,29,3; cmplw 30,3; ble 1f; mr 3,31; bl _s8009DF88_3; subf 30,29,3; 1:; mr 3,31; bl _s8009DF88_4; cmpw 30,3; bne 2f; mr 3,31; bl _s8009DF88_5; cmpwi 3,-1; beq 2f; mr 3,28; bl _s8009DF88_6; lwz 11,0x0(31); stw 11,0x0(28); lwz 9,0xc(11); addi 9,9,1; stw 9,0xc(11); b 3f; 2:; mr 3,31; bl _s8009DF88_7; add 4,3,29; mr 5,30; mr 3,28; bl _s8009DF88_8; 3:; mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8009DF88_0();
extern "C" void _s8009DF88_1();
extern "C" void _s8009DF88_2();
extern "C" void _s8009DF88_3();
extern "C" void _s8009DF88_4();
extern "C" void _s8009DF88_5();
extern "C" void _s8009DF88_6();
extern "C" void _s8009DF88_7();
extern "C" void _s8009DF88_8();
extern "C" void f_8009DF88() {}
