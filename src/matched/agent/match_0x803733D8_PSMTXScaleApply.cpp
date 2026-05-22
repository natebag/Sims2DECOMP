// 0x803733D8 PSMTXScaleApply (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="frsp f1,f1; .long 0xE0830000; frsp f2,f2; .long 0xE0A30008; frsp f3,f3; .long 0x10840058; .long 0xE0C30010; .long 0x10A50058; .long 0xE0E30018; .long 0x10C60098; .long 0xE1030020; .long 0xF0840000; .long 0x10E70098; .long 0xE0430028; .long 0xF0A40008; .long 0x110800D8; .long 0xF0C40010; .long 0x104200D8; .long 0xF0E40018; .long 0xF1040020; .long 0xF0440028"
extern "C" float f_803733D8() {}
