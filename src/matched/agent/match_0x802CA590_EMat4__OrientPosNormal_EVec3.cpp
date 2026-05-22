// 0x802CA590 EMat4::OrientPosNormal(EVec3 (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32702; mr 30,3; lfs f1,-7472(9); mr 29,4; mr 4,6; bl _s802CA590_0; mr 4,29; mr 3,30; bl _s802CA590_1; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802CA590_0();
extern "C" void _s802CA590_1();
extern "C" void f_802CA590() {}
