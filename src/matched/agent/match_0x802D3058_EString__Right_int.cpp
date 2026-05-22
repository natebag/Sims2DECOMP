// 0x802D3058 EString::Right(int) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 28,3; mr 29,5; mr 3,30; bl _s802D3058_0; lwz 4,0x0(30); subf 0,29,3; mr 3,28; add 4,4,0; bl _s802D3058_1; mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802D3058_0();
extern "C" void _s802D3058_1();
extern "C" void f_802D3058() {}
