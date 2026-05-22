// 0x800448EC HoodManager::GetMatrix(Neighbor (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; mr 30,5; mr 29,6; bl _s800448EC_0; stw 3,0x0(30); li 3,1; lha 0,0x4(28); stw 0,0x0(29); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800448EC_0();
extern "C" void f_800448EC() {}
