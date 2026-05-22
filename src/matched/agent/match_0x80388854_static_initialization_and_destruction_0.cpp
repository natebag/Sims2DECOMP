// 0x80388854 __static_initialization_and_destruction_0 (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 3,0; li 4,0; bl _s80388854_0; lwz 4,0x0(30); li 5,0; lwz 3,-22000(13); li 0,0; rlwinm 4,4,0,2,31; stw 4,0xc(3); lwz 4,0x4(30); lwz 3,-22000(13); rlwinm 4,4,0,2,31; stw 4,0x10(3); lwz 4,0x18(30); lwz 3,-22000(13); rlwimi 5,4,0,6,26; addi 4,5,0; rlwimi 4,0,26,5,5; stw 4,0x14(3); bl _s80388854_1; mr 3,31; bl _s80388854_2; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80388854_0();
extern "C" void _s80388854_1();
extern "C" void _s80388854_2();
extern "C" void f_80388854() {}
