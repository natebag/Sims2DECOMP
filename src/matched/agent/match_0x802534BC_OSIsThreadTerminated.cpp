// 0x802534BC OSIsThreadTerminated (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0x2c8(3); li 0,1; cmplwi 3,8; beq 0f; cmplwi 3,0; beq 0f; li 0,0; 0:; cmpwi 0,0; beq 1f; li 3,1; blr; 1:; li 3,0"
extern "C" int f_802534BC() {}
