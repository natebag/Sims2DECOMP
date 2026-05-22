// 0x802F0F84 EGraphics::Init(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; li 0,1; lwz 10,0x0(30); lis 11,-32702; stw 0,0x8(30); addi 9,1,8; lfs f0,-4060(11); mr 4,9; lha 3,0x48(10); li 5,255; stfs f0,0x8(1); li 6,1; stfs f0,0x8(9); add 3,30,3; stfs f0,0x4(9); lwz 0,0x4c(10); mtspr 8,0; blrl; lwz 9,0x0(30); lwz 0,0x22c(9); lha 3,0x228(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,-25912(13); lwz 9,0x338(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,0; beq 0f; li 3,1; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void f_802F0F84() {}
