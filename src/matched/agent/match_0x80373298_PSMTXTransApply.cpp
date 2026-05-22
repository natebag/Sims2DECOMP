// 0x80373298 PSMTXTransApply (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0830000; frsp f1,f1; .long 0xE0A30008; frsp f2,f2; .long 0xE0E30018; frsp f3,f3; .long 0xE1030028; .long 0xF0840000; .long 0x10A12956; .long 0xE0C30010; .long 0xF0A40008; .long 0x10E239D6; .long 0xE1230020; .long 0xF0C40010; .long 0x11034216; .long 0xF0E40018; .long 0xF1240020; .long 0xF1040028"
extern "C" float f_80373298() {}
