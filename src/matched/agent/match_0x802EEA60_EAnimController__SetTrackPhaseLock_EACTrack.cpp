// 0x802EEA60 EAnimController::SetTrackPhaseLock(EACTrack (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 30,5; fmr f31,f1; mr. 31,4; beq 3f; lwz 0,0xa8(31); cmpwi 0,1; bne 3f; lwz 0,0x74(31); cmpwi 0,-1; beq 0f; mulli 0,0,176; lwz 3,0x44(3); lwz 4,0x34(31); add 3,3,0; addi 3,3,140; bl _s802EEA60_0; 0:; cmpwi 30,0; beq 1f; lwz 4,0x34(31); addi 3,30,140; mr 5,31; li 6,0; bl _s802EEA60_1; lwz 0,0x34(30); b 2f; 1:; li 0,-1; 2:; stw 0,0x74(31); stfs f31,0x78(31); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s802EEA60_0();
extern "C" void _s802EEA60_1();
extern "C" void f_802EEA60() {}
