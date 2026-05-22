// 0x800B8010 global (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 5,4; lwz 3,-24508(13); li 4,38; lfs f1,-25840(9); li 6,0; li 7,0; bl _s800B8010_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800B8010_0();
extern "C" float f_800B8010() {}
