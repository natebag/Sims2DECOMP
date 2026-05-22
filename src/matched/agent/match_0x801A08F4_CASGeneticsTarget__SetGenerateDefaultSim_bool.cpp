// 0x801A08F4 CASGeneticsTarget::SetGenerateDefaultSim(bool) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,0; beq 0f; lwz 0,0x300(3); ori 0,0,16; stw 0,0x300(3); blr; 0:; lwz 0,0x300(3); rlwinm 0,0,0,28,26; stw 0,0x300(3)"
extern "C" void f_801A08F4() {}
