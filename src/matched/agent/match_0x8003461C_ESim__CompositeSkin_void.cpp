// 0x8003461C ESim::CompositeSkin(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; lwz 30,0x3d0(28); lwz 9,0x4(30); lha 3,0x150(9); addi 29,9,320; lwz 11,0x154(9); add 3,30,3; lha 0,0x140(9); mtspr 8,11; add 30,30,0; blrl; lbz 5,0x89(3); li 4,60; lwz 0,0x4(29); mr 3,30; extsb 5,5; mtspr 8,0; blrl; lwz 3,0x63c(28); bl _s8003461C_0; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8003461C_0();
extern "C" void f_8003461C() {}
