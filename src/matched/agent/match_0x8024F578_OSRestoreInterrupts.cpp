// 0x8024F578 OSRestoreInterrupts (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; mfmsr 4; beq 0f; ori 5,4,32768; b 1f; 0:; rlwinm 5,4,0,17,15; 1:; mtmsr 5; rlwinm 3,4,17,31,31"
extern "C" int f_8024F578() {}
