// 0x8037590C ARFree (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s8037590C_0; lwz 4,-22344(13); cmplwi 31,0; addi 0,4,-4; stw 0,-22344(13); beq 0f; lwz 4,-22344(13); lwz 0,0x0(4); stw 0,0x0(31); 0:; lwz 5,-22344(13); lwz 4,-22348(13); lwz 6,0x0(5); addi 0,4,1; lwz 5,-22352(13); stw 0,-22348(13); subf 0,6,5; stw 0,-22352(13); bl _s8037590C_1; lwz 3,-22352(13); lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037590C_0();
extern "C" void _s8037590C_1();
extern "C" void f_8037590C() {}
