// 0x801126E0 ObjTestSim::SetupInteractionColors(Interaction (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x3c(3); cmpwi 4,1; rlwinm 0,0,0,28,26; stw 0,0x3c(3); bne 0f; ori 0,0,16; stw 0,0x3c(3); 0:; lwz 0,0x3c(3); cmpwi 4,2; rlwinm 0,0,0,21,19; stw 0,0x3c(3); bnelr; ori 0,0,2048; stw 0,0x3c(3)"
extern "C" void f_801126E0() {}
