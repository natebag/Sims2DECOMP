// 0x801B5A50 G2DTarget::PushAptButtonFiltersForPlayer(int) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; cmpwi 31,1; bne 0f; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 1f; 0:; lwz 4,0x7c(30); mr 3,31; bl _s801B5A50_0; rlwinm 0,31,2,0,29; addi 9,30,288; stwx 3,9,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801B5A50_0();
extern "C" void f_801B5A50() {}
