// 0x8002C2C0 EIWallPart::SetVisible(bool) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; lwz 31,0x5c(29); bl _s8002C2C0_0; cmpwi 3,0; bne 1f; cmpwi 30,0; beq 0f; ori 31,31,1; b 3f; 0:; rlwinm 31,31,0,0,30; b 3f; 1:; cmpwi 30,0; beq 2f; ori 31,31,2; b 3f; 2:; rlwinm 31,31,0,31,29; 3:; stw 31,0x5c(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8002C2C0_0();
extern "C" void f_8002C2C0() {}
