// 0x802D2564 operator<<(EStream (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,4; bl _s802D2564_0; mr 30,3; addi 4,1,8; lwz 9,0x18(30); li 5,4; lfs f0,0xc(29); lha 3,0x38(9); lwz 0,0x3c(9); add 3,30,3; stfs f0,0x8(1); mtspr 8,0; blrl; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802D2564_0();
extern "C" void f_802D2564() {}
