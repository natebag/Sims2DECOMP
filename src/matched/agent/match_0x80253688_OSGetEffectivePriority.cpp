// 0x80253688 __OSGetEffectivePriority (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x2d4(3); lwz 5,0x2f4(3); b 2f; 0:; lwz 3,0x0(5); cmplwi 3,0; beq 1f; lwz 0,0x2d0(3); cmpw 0,4; bge 1f; mr 4,0; 1:; lwz 5,0x10(5); 2:; cmplwi 5,0; bne 0b; mr 3,4"
extern "C" int f_80253688() {}
