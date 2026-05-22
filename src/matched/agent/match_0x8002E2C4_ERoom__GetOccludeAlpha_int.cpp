// 0x8002E2C4 ERoom::GetOccludeAlpha(int, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,5; addi 3,3,160; li 5,0; bl _s8002E2C4_0; mr. 3,3; beq 0f; lwz 3,0x1c(3); cmpwi 3,0; bne 1f; 0:; lis 9,-32707; lfs f1,0xe48(9); b 2f; 1:; rlwinm 0,31,2,0,29; addi 9,3,8; lfsx f1,9,0; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8002E2C4_0();
extern "C" void f_8002E2C4() {}
