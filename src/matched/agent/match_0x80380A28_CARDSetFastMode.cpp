// 0x80380A28 CARDSetFastMode (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; lhz 3,-22006(13); beq 0f; li 0,1; b 1f; 0:; li 0,0; 1:; cmplwi 3,0; sth 0,-22006(13); beq 2f; li 3,1; blr; 2:; li 3,0"
extern "C" void f_80380A28() {}
