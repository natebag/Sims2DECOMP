// 0x80266B28 PADSetAnalogMode (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80266B28_0; lwz 5,-23180(13); rlwinm 6,31,8,0,23; lwz 4,-23168(13); mr 31,3; addi 8,5,0; not 7,8; lwz 0,-23164(13); andc 5,5,5; stw 6,-27644(13); and 4,4,7; and 0,0,7; stw 5,-23180(13); mr 3,8; stw 4,-23168(13); stw 0,-23164(13); bl _s80266B28_1; mr 3,31; bl _s80266B28_2; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80266B28_0();
extern "C" void _s80266B28_1();
extern "C" void _s80266B28_2();
extern "C" void f_80266B28() {}
