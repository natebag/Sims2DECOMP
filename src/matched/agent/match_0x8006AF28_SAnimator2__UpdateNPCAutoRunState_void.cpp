// 0x8006AF28 SAnimator2::UpdateNPCAutoRunState(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 0,0x600(31); cmpwi 0,0; beq 1f; lbz 0,0x5f9(31); cmpwi 0,0; bne 1f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x1a0(9); lwz 9,0x1a4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 0,0x108(31); cmpwi 0,1; beq 1f; li 0,1; li 30,1; stw 0,0x108(31); b 1f; 0:; lwz 0,0x108(31); cmpwi 0,0; beq 1f; stw 30,0x108(31); li 30,1; 1:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8006AF28() {}
