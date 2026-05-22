// 0x802D3610 operator+(char, (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); rlwinm 4,4,8,0,23; mr 30,3; sth 4,0x8(1); addi 4,1,8; lwz 5,0x0(5); bl _s802D3610_0; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802D3610_0();
extern "C" void f_802D3610() {}
