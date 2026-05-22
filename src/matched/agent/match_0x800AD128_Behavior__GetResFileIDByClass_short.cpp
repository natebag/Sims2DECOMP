// 0x800AD128 Behavior::GetResFileIDByClass(short) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 30,0x0(29); mr 3,4; lha 0,0x30(30); addi 30,30,48; add 29,29,0; bl _s800AD128_0; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800AD128_0();
extern "C" void f_800AD128() {}
