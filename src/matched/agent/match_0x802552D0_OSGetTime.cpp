// 0x802552D0 OSGetTime (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="0:; .long 0x7C6D42E6; .long 0x7C8C42E6; .long 0x7CAD42E6; cmpw 3,5; bne 0b"
extern "C" int f_802552D0() {}
