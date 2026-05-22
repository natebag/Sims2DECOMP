// 0x803758A4 ARAlloc (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s803758A4_0; lwz 31,-22352(13); lwz 4,-22344(13); add 0,31,30; stw 0,-22352(13); stw 30,0x0(4); lwz 5,-22344(13); lwz 4,-22348(13); addi 5,5,4; addi 0,4,-1; stw 5,-22344(13); stw 0,-22348(13); bl _s803758A4_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803758A4_0();
extern "C" void _s803758A4_1();
extern "C" void f_803758A4() {}
