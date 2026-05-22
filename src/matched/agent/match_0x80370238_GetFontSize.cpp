// 0x80370238 GetFontSize (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x0(3); cmplwi 0,89; bne 0f; lbz 0,0x1(3); cmplwi 0,97; bne 0f; lbz 0,0x2(3); cmplwi 0,121; bne 0f; lwz 3,0x4(3); blr; 0:; li 3,0"
extern "C" int f_80370238() {}
