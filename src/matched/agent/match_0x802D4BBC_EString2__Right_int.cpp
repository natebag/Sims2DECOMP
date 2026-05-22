// 0x802D4BBC EString2::Right(int) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 28,3; mr 30,5; mr 3,29; bl _s802D4BBC_0; subf 0,30,3; lwz 4,0x0(29); add 0,0,0; mr 3,28; add 4,0,4; bl _s802D4BBC_1; mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802D4BBC_0();
extern "C" void _s802D4BBC_1();
extern "C" void f_802D4BBC() {}
